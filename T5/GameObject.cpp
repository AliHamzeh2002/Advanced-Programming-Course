#include "src/rsdl.hpp"
#include "GameObject.hpp"
#include <iostream>

GameObject::GameObject(Point init_pos, int init_vx, int init_vy, int _height, int _width, std::string _img_src){
    position = init_pos;
    vx = init_vx;
    vy = init_vy;
    height = _height;
    width = _width;
    img_src = _img_src;
}

Point GameObject::get_position(){
    return position;
}

int GameObject::get_height(){
    return height;
}

int GameObject::get_width(){
    return width;
}

void GameObject::draw(Window* window){
    window->draw_img(img_src, Rectangle(position, width, height));
}

void GameObject::move(){
    position.x += vx * DELTA_TIME;
    position.y += vy * DELTA_TIME;
}

void GameObject::update(){
    move();
}

void GameObject::set_position(Point new_pos){
    position = new_pos;
}

void GameObject::set_vx(int new_vx){
    vx = new_vx;
}

Point GameObject::get_center(){
    return Point((2*position.x + width)/2, (2*position.y + height)/2);
}

Rectangle GameObject::get_object_rect(){
    return Rectangle(position, width, height);
}

int GameObject::get_vx(){
    return vx;
}