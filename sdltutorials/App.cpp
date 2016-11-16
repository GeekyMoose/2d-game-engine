#include "App.h"
using namespace std;


//------------------------------------------------------------------------------
// Constructors - Destructors
//------------------------------------------------------------------------------
App::App(){
	clog<<"[INFO] Create application."<<endl;
	isRunning = false;
}

App::~App(){
	clog<<"[INFO] Destroye application."<<endl;
}


//------------------------------------------------------------------------------
// Body function (Initialization - Stop)
//------------------------------------------------------------------------------
int App::executeApp(){
	clog<<"[INFO] Start running application..."<<endl;

	//Initialize application
	if(initApp()==false){
		clog<<"[ERR] Unbale to run application (Init failed)..."<<endl;
		return -1;
	}

	//Main execution loop
	SDL_Event sdlevent;
	while(isRunning){
		//General loop
		while(SDL_PollEvent(&sdlevent)){
			doEvent(&sdlevent);
		}
		doLoop();
		doRender();
	}

	//Stop application
	doCleanup();
	return 0;
}

bool App::initApp(){
	//Switch app running status (Can be init one time, then is running)
	if(isRunning){ return false; }
	isRunning = true;

	//Init SDL
	if(SDL_Init(SDL_INIT_EVERYTHING)<0){
		clog<<"[ERR] :: Unable to init App. SDL_Error: "<<SDL_GetError()<<endl;
		cerr<<"Unable to init App..."<<endl;
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
	if(window==NULL){
		clog<<"[ERR] :: Unable to start window. SDL_Error: "<<SDL_GetError()<<endl;
		cerr<<"Unable to init App..."<<endl;
		return false;
	}

	//Load SDL_Surface from the window
	screen = SDL_GetWindowSurface(window);
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(window);

	//TODO Temporary loading element ----------
	//Special element
	if(entity1.loadEntity("./data/images/yoshi.bmp", 64, 64, 8)==false){
		return false;
	}
	Entity::listEntities.push_back(&entity1);
	//Load map
	if(Area::areaControl.loadArea("./data/maps/1.area")==false){
		return false;
	}
	//TODO End temporary loading elements ----------
	return true;
}

void App::doCleanup(){
	//Cleanup each entity
	for(int i = 0; i<Entity::listEntities.size(); i++){
		if(!Entity::listEntities[i]) { continue; }
		Entity::listEntities[i]->doCleanup();
	}
	Entity::listEntities.clear();
	//Cleanup map
	Area::areaControl.cleanupArea();
	//Cleanup app
	SDL_FreeSurface(screen);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


//------------------------------------------------------------------------------
// Body function (Execution)
//------------------------------------------------------------------------------
void App::doEvent(SDL_Event* sdlevent){
	EventManager::onEvent(sdlevent);
}

void App::doLoop(){
	//Loop on each Entity
	for(int i = 0; i<Entity::listEntities.size(); i++){
		if(!Entity::listEntities[i]) { continue; }
		Entity::listEntities[i]->doLoop();
	}
}

void App::doRender(){
	//Render Map
	Area::areaControl.renderArea(screen, Camera::cameraControl.getX(), Camera::cameraControl.getY());
	//Render each Entity
	for(int i = 0; i<Entity::listEntities.size(); i++){
		if(!Entity::listEntities[i]) { continue; }
		Entity::listEntities[i]->doRender(screen);
	}
	//General refresh
	SDL_UpdateWindowSurface(window);
}


//------------------------------------------------------------------------------
// Override function (EventManager)
//------------------------------------------------------------------------------
void App::onExit(){
	isRunning = false;
}

void App::onKeyDown(SDL_Keysym keysym){
	switch(keysym.sym){
		//Arrow keys
		case SDL_SCANCODE_UP: Camera::cameraControl.moveCamera(0, 5); break;
		case SDL_SCANCODE_DOWN: Camera::cameraControl.moveCamera(0, -5); break;
		case SDL_SCANCODE_LEFT: Camera::cameraControl.moveCamera(5, 0); break;
		case SDL_SCANCODE_RIGHT: Camera::cameraControl.moveCamera(-5, 0); break;
		default: break;
	}
}