#ifndef SHOOTER_H

#define SHOOTER_H

#include "src/rsdl.hpp"
#include "GameObject.hpp"
#include "Bullet.hpp"
#include <vector>

class Shooter : public GameObject{
    public:
        Shooter(Point init_pos, int init_vx, int init_vy, int _height, int _width,
                int _bullet_vx, int _bullet_vy, std::string _img_src, std::string _bullet_img_src);
        virtual void update();
        void shoot(std::string shooter);
        std::vector<Bullet*> get_new_shot_bullets();
    protected:
        std::vector<Bullet*> new_shot_bullets;
        int bullet_vx;
        int bullet_vy;
        std::string bullet_img_src;
};

#endif