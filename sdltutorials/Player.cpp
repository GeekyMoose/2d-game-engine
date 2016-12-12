#include "Player.h"

Player::Player(){
}

void Player::doAnimate(){
	if(speedX==0){
		animEntity.setNbFrames(0);
	}
	else{
		animEntity.setNbFrames(8);
	}
}