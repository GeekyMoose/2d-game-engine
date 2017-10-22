#pragma once

#include "Entity.h"

class Player : public Entity {
    public:
        Player() = default;

        void doAnimate();
};
