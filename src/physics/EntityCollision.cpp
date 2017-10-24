#include "physics/EntityCollision.h"

std::vector<EntityCollision> EntityCollision::listEntityCollisions;

EntityCollision::EntityCollision() {
    entityA = NULL;
    entityB = NULL;
}
