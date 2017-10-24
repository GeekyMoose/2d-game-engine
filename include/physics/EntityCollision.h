#pragma once

#include "gameplay/Entity.h"

#include <vector>

class Entity;

class EntityCollision {
    public:
        static std::vector<EntityCollision> listEntityCollisions;

    public:
        Entity* entityA;
        Entity* entityB;

    public:
        EntityCollision();
};
