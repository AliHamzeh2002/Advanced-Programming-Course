#include "PowerUp.hpp"

using namespace std;

PowerUp::PowerUp(Point pos):
        GameObject(pos, POWER_UP_VX, POWER_UP_VY, POWER_UP_HEIGHT, POWER_UP_WIDTH, POWER_UP_IMG){
        int rand_num = rand() % 2;
        if (rand_num == 1) 
            power_type = ACCELERATOR;
        else
            power_type = SHIELD;
        life_span = POWER_UP_LIFE_SPAN;
}

void PowerUp::update(){
    life_span--;
}

bool PowerUp::is_time_finished(){
    return !life_span;
}

string PowerUp::get_power_type(){
    return power_type;
}