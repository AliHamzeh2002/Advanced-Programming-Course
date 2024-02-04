#ifndef GAME_CONTROLLER_H

#define GAMER_CONTROLLER_H

#include "constants.hpp"
#include "src/rsdl.hpp"
#include "Rocket.hpp"
#include "Bullet.hpp"
#include "Shooter.hpp"
#include "Enemy.hpp"
#include "MovingEnemy.hpp"
#include "Hostage.hpp"
#include "MapReader.hpp"
#include "PowerUp.hpp"
#include <vector>
#include <fstream>

class GameController{
    public:
        GameController(std::string map_file_name);
        void run_game();
    private:
        void run_level();
        void initialize_level();
        void handle_events();
        void update();
        void draw();
        void update_enemies();
        void update_bullets();
        void update_rocket();
        void update_power_ups();
        void update_hostages();
        void update_bullets_collisons();
        void remove_all_objects();
        void show_game_result();
        void check_power_up_collisons();
        void generate_objects(std::vector<ObjectOnMapData> objects_on_map);
        void update_bullet_collisons(Bullet* bullet);
        void update_enemy_bullet_collisions(Bullet* bullet);
        void update_rocket_bullet_collisions(Bullet* bullet);
        void add_new_shot_bullets(Shooter* shooter);
        void remove_enemy(Enemy* enemy);
        void remove_bullet(Bullet* bullet);
        void remove_hostage(Hostage* hostage);
        void remove_power_up(PowerUp* hostage);  
        void show_msg(std::string msg);
        void make_power_up(Point pos);
        bool is_out_of_screen(GameObject* game_object);
        bool check_collison(GameObject* obj1, GameObject* obj2);
        bool should_make_power_up();
        Point calc_pos_on_window(int row, int col);
        int num_of_levels;
        int num_of_cols;
        int num_of_rows;
        int current_level;
        bool game_running;
        bool level_running;
        bool game_won;
        MapReader map_reader;
        Window window;
        Rocket* rocket;
        std::vector<Enemy*> enemies;
        std::vector<Bullet*> bullets;
        std::vector<Hostage*> hostages;
        std::vector<PowerUp*> power_ups;
};

#endif