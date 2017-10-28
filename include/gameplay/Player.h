#pragma once

#include "helper/Platform.h"
#include "Entity.h"

class Player : public Entity {
    public:
        Player() = default;

        void doAnimate();
};
