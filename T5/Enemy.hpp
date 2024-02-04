#ifndef ENEMY_H

#define ENEMY_H

#include "Shooter.hpp"
#include <ctime>

class Enemy : public Shooter{
    public:
        Enemy(Point init_pos);
        virtual void update();
    private:
        bool is_time_to_shoot();
        int update_counter;
        std::string type;

};

#endif