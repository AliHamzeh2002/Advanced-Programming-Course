#include "Bullet.hpp"

using namespace std;

Bullet::Bullet(Point init_pos, int _vx, int _vy, string _img_src, string _shooter):
                GameObject(init_pos, _vx , _vy , BULLET_HEIGHT, BULLET_WIDTH, _img_src){
            shooter = _shooter;
}

string Bullet::get_shooter(){
    return shooter;
}
