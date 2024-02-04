#ifndef CONSTANTS_H

#define CONSTANTS_H

#include "src/rsdl.hpp"

const int BULLET_WIDTH = 20;
const int BULLET_HEIGHT = 20;
const int DELTA_TIME = 1;
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;
const int DELAY_TIME = 50;
const int ENEMY_VX = 0;
const int ENEMY_VY = 0;
const int ENEMY_HEIGHT = 50;
const int ENEMY_WIDTH = 50;
const int ENEMY_BULLET_VX = 0;
const int ENEMY_BULLET_VY = 10;
const int INTERVAL_BETWEEN_SHOTS = 50;
const int MOVING_ENEMY_VX = 5;
const int ROCKET_Y_SPEED = 10;
const int ROCKET_X_SPEED = 10;
const int INIT_VX = 0;
const int INIT_VY = 0;
const int ROCKET_HEIGHT = 50;
const int ROCKET_WIDTH = 50; 
const int ROCKET_BULLET_VY = -12;
const int ROCKET_BULLET_VX = 0;
const int HOSTAGE_VX = 0;
const int HOSTAGE_VY = 0;
const int HOSTAGE_WIDTH = 50;
const int HOSTAGE_HEIGHT = 50;
const int SHOW_MSG_DELAY = 2000;
const int POWER_UP_VX = 0;
const int POWER_UP_VY = 0;
const int POWER_UP_HEIGHT = 50;
const int POWER_UP_WIDTH = 50;
const int POWER_UP_LIFE_SPAN = 200;
const int POWER_UP_MAKE_CHANCE = 70;
const int MSG_SIZE = 60;
const int ACCELERATOR_RATIO = 3;
const char UP_KEY = 'w';
const char DOWN_KEY = 's';
const char RIGHT_KEY = 'd';
const char LEFT_KEY = 'a';
const char SPACE = ' ';
const char DOT = '.';
const char ENEMY_IDENTIFIER = 'E';
const char MOVING_ENEMY_IDENTIFIER = 'M';
const char HOSTAGE_IDENTIFIER = 'S';
const Point ORIGIN_POINT(0,0);
const std::string ACCELERATOR = "accelerator";
const std::string SHIELD = "shield";
const std::string LEVEL_STRING = "Level: ";
const std::string GAME_WON_MSG = "YOU WON! ";
const std::string GAME_LOST_MSG = "YOU LOST ";
const std::string FONT = "./assets/imgs/font/FreeSans.ttf";
const std::string BACKGROUND_IMG = "./assets/imgs/background.png";
const std::string ENEMY = "enemy";
const std::string ENEMY_IMG = "./assets/imgs/enemy.png";
const std::string ENEMY_BULLET_IMG = "./assets/imgs/enemy_bullet.png";
const std::string ROCKET = "rocket";
const std::string ROCKET_IMG = "./assets/imgs/rocket.png";
const std::string ROCKET_BULLET_IMG = "./assets/imgs/bullet.png";
const std::string HOSTAGE_IMG = "./assets/imgs/hostage.png";
const std::string POWER_UP_IMG = "assets/imgs/power_up.png";

#endif