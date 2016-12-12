#include "Player.h"

Player::Player(){
}

bool Player::loadEntity(const char * file, int w, int h, int nbFrames){
	return Entity::loadEntity(file, w, h, nbFrames);
}

void Player::doLoop(){
	Entity::doLoop();
}

void Player::doRender(SDL_Surface * dest){
	Entity::doRender(dest);
}

void Player::doCleanup(){
	Entity::doCleanup();
}

void Player::doAnimate(){
	Entity::doAnimate();
	if(speedX==0){
		animEntity.setNbFrames(0);
	}
	else{
		animEntity.setNbFrames(8);
	}
}

void Player::doCollision(Entity * other){
	Entity::doCollision(other);
}