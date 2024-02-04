#ifndef GAME_OBJ_H

#define GAME_OBJ_H

#include "constants.hpp"
#include "src/rsdl.hpp"

class GameObject{
    public:
        GameObject(Point init_pos, int init_vx, int init_vy, int _height, int _width, std::string _img_src);
        virtual void move();
        virtual void update();
        void draw(Window* window);
        void set_position(Point new_pos);
        void set_vx(int new_vx);
        int get_height();
        int get_width();
        int get_vx();
        Point get_position();
        Point get_center();
        Rectangle get_object_rect();
    protected:
        Point position;
        int vx;
        int vy;
        int height;
        int width;
        std::string img_src;
};


#endif