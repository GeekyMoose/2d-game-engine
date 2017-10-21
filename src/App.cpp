#include "App.h"


//------------------------------------------------------------------------------
// Constructors - Destructor
//------------------------------------------------------------------------------
App::App() {
    LOG_INFO("Create application.");
    isRunning = false;
}

App::~App() {
    LOG_INFO("Destroy application.");
}


//------------------------------------------------------------------------------
// Body function (Initialization - Stop)
//------------------------------------------------------------------------------
int App::executeApp() {
    //App should be already running
    if(isRunning) {
        return false;
    }
    LOG_INFO("Start running application...");

    //Initialize application
    if(initApp() == false) {
        LOG_ERROR("nable to run application (Init failed)...");
        return -1;
    }
    isRunning = true; //Here, actually start running

    //Main execution loop
    SDL_Event sdlevent;
    while(isRunning) {
        while(SDL_PollEvent(&sdlevent)) {
            doEvent(&sdlevent); //process event
        }
        doLoop(); //Do all modification (Movement, animation etc)
        doRender(); //Update display
    }

    //Stop application
    doCleanup();
    return 0;
}

bool App::initApp() {
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        LOG_ERROR(SDL_GetError());
        return false;
    }

    //Create SDL window for screen
    window = SDL_CreateWindow(
        WINDOWS_TITLE,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if(window==NULL) {
        LOG_ERROR(SDL_GetError());
        return false;
    }

    //Load SDL_Surface from the window
    screen = SDL_GetWindowSurface(window);
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);

    //Create and load players
    LOG_INFO("Load players");
    if(player1.loadEntity("./data/images/yoshi.png", 64, 64, 8)==false) {
        return false;
    }


    Entity::listEntities.push_back(&player1);

    //Set camera mode and target to players
    Camera::cameraControl.targetMode = TARGET_MODE_CENTER;
    Camera::cameraControl.setTarget(&player1.x, &player1.y);

    //Load area
    if(Area::areaControl.loadArea("./data/maps/area1.area")==false) {
        LOG_ERROR(": Unable to load the area (./data/maps/area1.area).");
        return false;
    }
    return true;
}

void App::doCleanup() {
    //Cleanup each entity
    for(int i = 0; i<Entity::listEntities.size(); i++) {
        if(!Entity::listEntities[i]) { continue; }
        Entity::listEntities[i]->doCleanup();
    }
    Entity::listEntities.clear();
    //Cleanup area
    Area::areaControl.cleanupArea();
    //Cleanup App
    SDL_FreeSurface(screen);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


//------------------------------------------------------------------------------
// Body function (Execution)
//------------------------------------------------------------------------------
void App::doEvent(SDL_Event* sdlevent) {
    EventManager::onEvent(sdlevent);
}

void App::doLoop() {
    //Loop on each Entity
    for(int i = 0; i<Entity::listEntities.size(); i++) {
        if(!Entity::listEntities[i]) { continue; }
        Entity::listEntities[i]->doLoop();
    }

    //Loop on each collision
    for(int i=0; i<EntityCollision::listEntityCollisions.size(); i++) {
        Entity* entityA = EntityCollision::listEntityCollisions[i].entityA;
        Entity* entityB = EntityCollision::listEntityCollisions[i].entityB;

        if(entityA == NULL || entityB == NULL) {
            continue;
        }

        if(entityA->doCollision(entityB)) {
            entityB->doCollision(entityA);
        }
    }
    EntityCollision::listEntityCollisions.clear();

    //FPS management
    FPS::FPSControl.onLoop();
    char buffer[255];
    sprintf(buffer, "%d", FPS::FPSControl.getFPS());
    SDL_SetWindowTitle(window, buffer); //Display FPS on title
}

void App::doRender() {
    //Refresh background to white
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));
    //Render Map
    Area::areaControl.renderArea(screen, -Camera::cameraControl.getX(), -Camera::cameraControl.getY());
    //Render each Entity
    for(int i = 0; i<Entity::listEntities.size(); i++) {
        if(!Entity::listEntities[i]) { continue; }
        Entity::listEntities[i]->doRender(screen);
    }
    //General refresh
    SDL_UpdateWindowSurface(window);
}


//------------------------------------------------------------------------------
// Override function (EventManager)
//------------------------------------------------------------------------------
void App::onExit() {
    isRunning = false;
}

void App::onKeyUp(SDL_Keysym keysym) {
    switch(keysym.sym) {
        //Arrow keys
        case SDLK_LEFT: player1.moveLeft = false;
        case SDLK_RIGHT: player1.moveRight = false;
        case SDLK_SPACE: player1.jump();
        default: break;
    }
}

void App::onKeyDown(SDL_Keysym keysym) {
    switch(keysym.sym) {
        //Arrow keys
        case SDLK_LEFT: player1.moveLeft = true;
        case SDLK_RIGHT: player1.moveRight = true;
        default: break;
    }
}

void App::onKeyRight(SDL_Keysym keysym) {}
void App::onKeyLeft(SDL_Keysym keysym) {}
void App::onSpace(SDL_Keysym keysym) {}
