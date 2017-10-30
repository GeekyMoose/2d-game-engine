#include "core/App.h"

#include "core/FPSManager.h"

#include <iostream>
#include <ostream>

#if PLATFORM_WINDOWS
#   include <SDL.h>
#elif PLATFORM_LINUX
#   include <SDL2/SDL.h>
#endif

//------------------------------------------------------------------------------
// Constructors - Destructor
//------------------------------------------------------------------------------
App::App() {
    LOG_INFO("Create application.");
    isRunning = false;
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

    this->m_window.initialize();

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
    Area::areaControl.cleanupArea();
    SDL_Quit();
}


//------------------------------------------------------------------------------
// Body function (Execution)
//------------------------------------------------------------------------------
void App::doEvent(SDL_Event* sdlevent) {
    //EventManager::onEvent(sdlevent);
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
    FPSManager::getInstance().update();
    char buffer[255];
}

void App::doRender() {
    //Refresh background to white
    SDL_Surface* surface = this->m_window.getSurface();
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));
    //Render Map
    Area::areaControl.renderArea(surface, -Camera::cameraControl.getX(), -Camera::cameraControl.getY());
    //Render each Entity
    for(int i = 0; i<Entity::listEntities.size(); i++) {
        if(!Entity::listEntities[i]) { continue; }
        Entity::listEntities[i]->doRender(surface);
    }
    //General refresh
    SDL_UpdateWindowSurface(this->m_window.getRoot());
}