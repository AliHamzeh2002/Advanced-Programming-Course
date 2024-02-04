#include "MovingEnemy.hpp"

MovingEnemy::MovingEnemy(Point init_pos):Enemy(init_pos){
    vx = MOVING_ENEMY_VX;
}

void MovingEnemy::update(){
    int next_pos_x = vx * DELTA_TIME + position.x;
    if (next_pos_x + width > SCREEN_WIDTH || next_pos_x < 0)
        vx *= -1;
    Enemy::update();
}