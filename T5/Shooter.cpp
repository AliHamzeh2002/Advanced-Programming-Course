#include "Shooter.hpp"
#include <algorithm>

using namespace std;

Shooter::Shooter(Point init_pos, int init_vx, int init_vy, int _height,
                 int _width, int _bullet_vx, int _bullet_vy, string _img_src, string _bullet_img_src):
        GameObject( init_pos, init_vx, init_vy, _height, _width, _img_src){
            bullet_vx = _bullet_vx;
            bullet_vy = _bullet_vy;
            bullet_img_src = _bullet_img_src;
        }

vector<Bullet*> Shooter::get_new_shot_bullets(){
    return new_shot_bullets;
}

void Shooter::update(){
    GameObject::update();
    new_shot_bullets.clear();
}

void Shooter::shoot(string shooter){
    Point bullet_pos(get_center().x, get_center().y);
    Bullet* new_bullet = new Bullet(bullet_pos, bullet_vx, bullet_vy, bullet_img_src, shooter);
    new_shot_bullets.push_back(new_bullet);
}

