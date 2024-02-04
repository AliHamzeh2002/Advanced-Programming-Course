#include "Enemy.hpp"
#include <ctime>

using namespace std;

Enemy::Enemy(Point init_pos):
        Shooter(init_pos, ENEMY_VX, ENEMY_VY, ENEMY_HEIGHT, ENEMY_WIDTH, ENEMY_BULLET_VX,
         ENEMY_BULLET_VY, ENEMY_IMG, ENEMY_BULLET_IMG){
             update_counter = rand() % INTERVAL_BETWEEN_SHOTS;
}

bool Enemy::is_time_to_shoot(){
    return update_counter >= INTERVAL_BETWEEN_SHOTS;
}

void Enemy::update(){
    Shooter::update();
    if (is_time_to_shoot()){
        shoot(ENEMY);
        update_counter = 0;
    }
    update_counter++;
}

