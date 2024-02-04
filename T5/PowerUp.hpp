#ifndef POWER_UP_H

#define POWER_UP_H

#include "constants.hpp"
#include "src/rsdl.hpp"
#include "GameObject.hpp"

class PowerUp : public GameObject{
    public:
        PowerUp(Point pos);
        virtual void update();
        bool is_time_finished();
        std::string get_power_type();
    private: 
        std::string power_type;
        int life_span;
        int update_counter;
};

#endif