#ifndef ROCKET_H

#define ROCKET_H

#include "src/rsdl.hpp"
#include "Shooter.hpp"
#include "Bullet.hpp"
#include "PowerUp.hpp"
#include <vector>

class Rocket : public Shooter{
    public:
        Rocket(Point init_pos);
        void handle_event(Event event);
        void add_power_up(PowerUp* power_up);
        virtual void move();
        virtual void update(); 
        bool has_power_type(std::string power_type);
    private:
        void update_power_ups();
        bool is_in_the_screen();
        std::vector<PowerUp*> power_ups;
};

#endif