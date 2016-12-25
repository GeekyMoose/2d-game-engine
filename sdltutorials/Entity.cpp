#include "Entity.h"

//Singleton variable
std::vector<Entity*> Entity::listEntities;

Entity::Entity(){
	surfaceEntity	= NULL;
	x				= 0.0f;
	y				= 0.0f;
	width			= 0;
	height			= 0;
	moveLeft		= false;
	moveRight		= false;
	type			= ENTITY_TYPE_GENERIC;
	dead			= false;
	flags			= ENTITY_FLAG_GRAVITY;
	speedX			= 0;
	speedY			= 0;
	accelX			= 0;
	accelY			= 0;
	maxSpeedX		= 10;
	maxSpeedY		= 10;
	currentFrameCol	= 0;
	currentFrameRow	= 0;
	col_x			= 0;
	col_y			= 0;
	col_width		= 0;
	col_height		= 0;
	canJump			= false;
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
	//Get current movement direction and set acceleration
	if(moveLeft==false && moveRight==false){
		stopMove();
	}
	if(moveLeft==true){
		accelX = -0.5;
	}
	else if(moveRight==true){
		accelX = 0.5;
	}
	if(flags & ENTITY_FLAG_GRAVITY){ accelY = 0.75f; }
	//Change speed (Add acceleration to speed).
	//getSpeedFactor gives the ratio to apply (See FPS class)
	speedX += accelX*FPS::FPSControl.getSpeedFactor();
	speedY += accelY*FPS::FPSControl.getSpeedFactor();
	//Speed limiter
	if(speedX>maxSpeedX){	speedX = maxSpeedX; }
	if(speedX<-maxSpeedX){	speedX = -maxSpeedX; }
	if(speedY>maxSpeedY){	speedY = maxSpeedY; }
	if(speedY<-maxSpeedY){	speedY = -maxSpeedY; }
	//Apply the movement
	doAnimate();
	doMove(speedX, speedY);
}

void Entity::doRender(SDL_Surface * dest){
	if(dest==NULL || surfaceEntity == NULL){ return;}
	//Work only with sprite sheet with one column
	Surface::doDraw(surfaceEntity, 
					currentFrameCol*width, 
					(currentFrameRow+animEntity.getCurrentFrame())*height, 
					width, 
					height, 
					dest, 
					x-Camera::cameraControl.getX(), //Use upper left corner
					y-Camera::cameraControl.getY());
}

void Entity::doCleanup(){
	SDL_FreeSurface(surfaceEntity);
	surfaceEntity = NULL;
}

void Entity::doAnimate(){
	//Col 0 is the moveLeft animation, 1 is for right animation
	if(moveLeft==true){
		currentFrameCol = 0;
	}
	else if(moveRight==true){
		currentFrameCol = 1;
	}
	animEntity.doAnimate(); //Process anim
}

bool Entity::doCollision(Entity * other){
	jump();
	return true;
}

void Entity::doMove(float moveX, float moveY){
	if(moveX == 0 && moveY == 0){ return; }
	double newX = 0;
	double newY = 0;

	//Get the actual movement to do (Number of pixel for this movement)
	moveX *= FPS::FPSControl.getSpeedFactor();
	moveY *= FPS::FPSControl.getSpeedFactor();

	//Define distance between 2 position to check
	//SpeedFactor is always smaller than moveX (and moveY)
	if(moveX != 0) {
		if(moveX >= 0){ newX =  FPS::FPSControl.getSpeedFactor(); }
		else{			newX = -FPS::FPSControl.getSpeedFactor(); }
	}
	if(moveY != 0) {
		if(moveY >= 0){ newY =  FPS::FPSControl.getSpeedFactor(); }
		else{			newY = -FPS::FPSControl.getSpeedFactor(); }
	}

	//Test each positions on the way till final position
	//For ex, if go 4 pixel forward but wall at 2, should stop before pixel 2.
	while(true) {
		//If entity is a ghost, pass through walls
		if(flags & ENTITY_FLAG_GHOST) {
			//needed just to create collision event for other entities
			posValid((int)(x+newX), (int)(y+newY));
			x += newX;
			y += newY;
		}
		//Then, normal movement
		else{
			if(posValid((int)(x+newX), (int)(y))){
				x+=newX;
			}
			else{
				speedX = 0;
			}

			if(posValid((int)(x), (int)(y+newY))) {
				y+= newY;
			}
			else{
				if(moveY > 0){ canJump = true; }
				speedY = 0;
			}
		}

		//Update reminding movement to do
		moveX += -newX;
		moveY += -newY;
		if(newX > 0 && moveX <= 0){ newX = 0; }
		if(newX < 0 && moveX >= 0){ newX = 0; }
		if(newY > 0 && moveY <= 0){ newY = 0; }
		if(newY < 0 && moveY >= 0){ newY = 0; }
		if(moveX == 0){ newX = 0; }
		if(moveY == 0){ newY = 0; }
		if(moveX == 0 && moveY == 0){ break; }
		if(newX  == 0 && newY == 0) { break; }
	}
}

void Entity::stopMove(){
	if(speedX > 0) {
		accelX = -1;
	}
	if(speedX < 0) {
		accelX = 1;
	}
	if(speedX < 2.0f && speedX > -2.0f) {
		accelX = 0;
		speedX = 0;
	}
}

bool Entity::collides(int oX, int oY, int oW, int oH){
	//Set all sides positions
	int left1 = (int)x + col_x;
	int left2 = oX;
	int right1 = left1 + width - 1 - col_width; //-1 for true coordinate of the side
	int right2 = oX + oW - 1;
	int top1 = (int)y + col_y;
	int top2 = oY;
	int bottom1 = top1 + height - 1 - col_height;
	int bottom2 = oY + oH - 1;

	//Collision test
	if(top1>bottom2){ return false; }
	if(bottom1<top2){ return false; }
	if(right1<left2){ return false; }
	if(left1>right2){ return false; }
	return true;
}

bool Entity::jump(){
	if(!canJump){ return false; }
	speedY = -maxSpeedY;
	return true;
}

bool Entity::posValid(int newX, int newY){
	bool isValid	= true;
	int startX		= (newX + col_x) / TILE_SIZE;
	int startY		= (newY + col_y) / TILE_SIZE;
	int endX		= ((newX + col_x) + width - col_width - 1) / TILE_SIZE;
	int endY		= ((newY + col_y) + height - col_height - 1) / TILE_SIZE;

	for(int iY = startY; iY <= endY; iY++) {
		for(int iX = startX; iX <= endX; iX++) {
			Tile* tile = Area::areaControl.getTile(iX*TILE_SIZE, iY*TILE_SIZE);
			if(posValidTile(tile) == false) {
				isValid = false;
			}
		}
	}
	if((flags & ENTITY_FLAG_MAPONLY) == false) {
		for(int i = 0; i < listEntities.size(); i++) {
			if(posValidEntity(listEntities[i], newX, newY) == false) {
				isValid = false;
			}
		}
	}
	return isValid;
}

bool Entity::posValidTile(Tile* tile){
	if(tile == NULL){ return true; }
	if(tile->typeID == TILE_TYPE_BLOCK) {
		return false;
	}
	return true;
}

bool Entity::posValidEntity(Entity * entity, int newX, int newY){
	//If entity is not valid, return false
	if(entity==NULL || this == entity || entity->dead == true){
		return true;
	}
	//If entity doesn't collide with other entities, return false
	if((entity->flags ^ ENTITY_FLAG_MAPONLY) == false){
		return true;
	}
	//If collision happened, add in collision list
	if(entity->collides(newX+col_x, newY+col_y, width-col_width-1, height-col_height-1)){
		EntityCollision entityCol;
		entityCol.entityA = this;
		entityCol.entityB = entity;
		EntityCollision::listEntityCollisions.push_back(entityCol);
		return false;
	}
	return true;
}
