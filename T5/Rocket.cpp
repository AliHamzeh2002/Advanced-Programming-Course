#include "src/rsdl.hpp"
#include "Rocket.hpp"

using namespace std;


Rocket::Rocket(Point init_pos):
                Shooter(init_pos, INIT_VY, INIT_VY, ROCKET_HEIGHT, ROCKET_WIDTH, ROCKET_BULLET_VX,
                ROCKET_BULLET_VY, ROCKET_IMG, ROCKET_BULLET_IMG){

}

bool Rocket::is_in_the_screen(){
    Point next_pos = Point(position.x + DELTA_TIME * vx, position.y + DELTA_TIME * vy);
    return !(next_pos.x < 0 || next_pos.x + width > SCREEN_WIDTH || next_pos.y < 0 || next_pos.y + height > SCREEN_HEIGHT);
}

void Rocket::update(){
    Shooter::update();
    update_power_ups();
    bullet_vy = ROCKET_BULLET_VY;
    if (has_power_type(ACCELERATOR))
        bullet_vy = ROCKET_BULLET_VY * ACCELERATOR_RATIO;
}

void Rocket::move(){
    if (is_in_the_screen())
        Shooter::move();
}

void Rocket::update_power_ups(){
    vector<PowerUp*> power_ups_copy = power_ups;
    for (int i = 0; i < power_ups_copy.size(); i++){
        PowerUp* power_up = power_ups_copy[i];
        power_up->update();
        if (power_up->is_time_finished()){
            power_ups.erase(i + power_ups.begin());
            delete power_up;
        }
    }
}

void Rocket::add_power_up(PowerUp* power_up){
    power_ups.push_back(power_up);
}

bool Rocket::has_power_type(string power_type){
    for (auto power_up : power_ups){
        if (power_up->get_power_type() == power_type)
            return true;
    }
    return false;
}

void Rocket::handle_event(Event event){
    Event::EventType type = event.get_type();
    char key = event.get_pressed_key();
    switch (key)
    {
        case UP_KEY:
            if (type == Event::KEY_PRESS)
                vy = -ROCKET_Y_SPEED;
            else
                vy = 0;
            break;
        case DOWN_KEY:
            if (type == Event::KEY_PRESS)
                vy = ROCKET_Y_SPEED;
            else
                vy = 0;
            break;
        case RIGHT_KEY:
            if (type == Event::KEY_PRESS)
                vx = ROCKET_X_SPEED;
            else
                vx = 0;
            break;
        case LEFT_KEY:
            if (type == Event::KEY_PRESS)
                vx = -ROCKET_X_SPEED;
            else
                vx = 0;
            break;
        case SPACE:
            if (type == Event::KEY_PRESS)
                shoot(ROCKET);
        default:
            break;
    }
}




