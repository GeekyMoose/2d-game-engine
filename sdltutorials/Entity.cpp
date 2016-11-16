#include "Entity.h"

std::vector<Entity*> Entity::listEntities;

Entity::Entity(){
	surfaceEntity = NULL;
	x = 0.0f;
	y = 0.0f;
	width = 0;
	height = 0;
}

bool Entity::loadEntity(const char* file, int w, int h, int nbFrames){
	surfaceEntity = Surface::doLoad(file);
	if(surfaceEntity==NULL){ return false; }
	Surface::transparent(surfaceEntity, 255, 0, 255);
	width = w;
	height = h;
	animEntity.setNbFrames(nbFrames);
	return true;
}

void Entity::doLoop(){
	animEntity.doAnimate();
}

void Entity::doRender(SDL_Surface * dest){
	if(dest==NULL || surfaceEntity == NULL){ return;}
	Surface::doDraw(surfaceEntity, 0, animEntity.getCurrentFrame()*height, width, height, dest, 0, 0);
}

void Entity::doCleanup(){
	SDL_FreeSurface(surfaceEntity);
	surfaceEntity = NULL;
}
