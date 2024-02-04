#ifndef BULLET_H

#define BULLET_H

#include "GameObject.hpp"
#include "src/rsdl.hpp"

class Bullet : public GameObject{
    public:
        Bullet(Point init_pos,int _vx, int _vy, std::string img_src, std::string _shooter);
        std::string get_shooter();
    private:
        std::string shooter;
};

#endif