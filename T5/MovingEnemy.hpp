#ifndef MOVING_ENEMY_H

#define MOVING_ENEMY_H

#include "Enemy.hpp"

class MovingEnemy : public Enemy{
    public:
        MovingEnemy(Point init_pos);
        virtual void update();
};

#endif