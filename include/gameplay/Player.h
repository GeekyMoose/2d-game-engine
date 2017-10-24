#pragma once

#include "gameplay/Entity.h"

class Player : public Entity {
    public:
        Player() = default;

        void doAnimate();
};
