#pragma once
#include <vector>
#include "Entity.h"

class Entity;

class EntityCollision{
public:
	static std::vector<EntityCollision> listEntityCollisions;
public:
	Entity* entityA;
	Entity* entityB;
public:
	EntityCollision();
};