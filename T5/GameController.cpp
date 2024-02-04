#include "GameController.hpp"
#include "src/rsdl.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>

using namespace std;


GameController::GameController(string map_file_name) : window(SCREEN_WIDTH, SCREEN_HEIGHT), map_reader(map_file_name){
    num_of_levels = map_reader.get_num_levels();
    num_of_rows = map_reader.get_num_rows();
    num_of_cols = map_reader.get_num_cols();
    game_running = true;
    srand(time(0));
}

void GameController::run_game(){
    current_level = 1;
    game_won = false;
    while (game_running){
        run_level();
        current_level++;
        if (current_level > num_of_levels)
            game_running = false;
    }
    show_game_result();
}

void GameController::show_game_result(){
    if (game_won)
        show_msg(GAME_WON_MSG);
    else
        show_msg(GAME_LOST_MSG);
}

void GameController::run_level(){
    string level_msg = LEVEL_STRING + to_string(current_level); 
    show_msg(level_msg);
    initialize_level();
    level_running = true;
    while (level_running){
        handle_events();
        update();
        draw();
        delay(DELAY_TIME);
    }
    remove_all_objects();
}

void GameController::remove_all_objects(){
    vector<Enemy*> enemies_copy = enemies;
    for(auto enemy : enemies_copy)
        remove_enemy(enemy);
    vector<Bullet*> bullets_copy = bullets;
    for(auto bullet : bullets_copy)
        remove_bullet(bullet);
    vector<Hostage*> hostages_copy = hostages;
    for (auto hostage : hostages_copy)
        remove_hostage(hostage);
    vector<PowerUp*> power_ups_copy = power_ups;
    for (auto power_up : power_ups_copy)
        remove_power_up(power_up);
    delete rocket;
}

void GameController::initialize_level(){
    vector<ObjectOnMapData> objects_on_map = map_reader.read_next_level();
    generate_objects(objects_on_map);
    int rocket_col = rand() % num_of_cols;
    Point rocket_pos = calc_pos_on_window(num_of_rows - 1, rocket_col);
    rocket = new Rocket(rocket_pos);
}

void GameController::generate_objects(vector<ObjectOnMapData> objects_on_map){
    for (auto obj_on_map : objects_on_map){
        Point pos = calc_pos_on_window(obj_on_map.row, obj_on_map.col);
        char obj_type = obj_on_map.object_type;
        if (obj_type == ENEMY_IDENTIFIER)
            enemies.push_back(new Enemy(pos));
        else if (obj_type == MOVING_ENEMY_IDENTIFIER)
            enemies.push_back(new MovingEnemy(pos));
        else if (obj_type == HOSTAGE_IDENTIFIER)
            hostages.push_back(new Hostage(pos));
    }
}

Point GameController::calc_pos_on_window(int row, int col){
    return Point(col* SCREEN_HEIGHT / num_of_cols, row * SCREEN_HEIGHT / num_of_rows);
}

void GameController::handle_events(){
    while(window.has_pending_event()) {
        Event event = window.poll_for_event();
        Event::EventType type = event.get_type();
        if (type == Event::KEY_PRESS || type == Event::KEY_RELEASE)
            rocket->handle_event(event);
        else if (type == Event::QUIT){
            level_running = false;
            game_running = false;
            break;
        }
    }
}

void GameController::update(){
    update_bullets();
    update_rocket();
    update_enemies();
    update_power_ups();
    update_hostages();
    if (enemies.size() == 0){
        level_running = false;
        if (current_level == num_of_levels)
            game_won = true;
    }
}

void GameController::update_bullets(){
    update_bullets_collisons();
    vector<Bullet*> bullets_copy = bullets;
    for (auto bullet : bullets_copy){
        bullet->update();
        if (is_out_of_screen(bullet))
            remove_bullet(bullet);
    }
}

void GameController::check_power_up_collisons(){
    vector<PowerUp*> power_ups_copy = power_ups;
    for (int i = 0; i < power_ups_copy.size(); i++){
        PowerUp* power_up = power_ups_copy[i];
        if (check_collison(power_up, rocket)){
            rocket->add_power_up(power_up);
            power_ups.erase(i + power_ups.begin());
        }
    }
}

void GameController::update_rocket(){
    add_new_shot_bullets(rocket);
    check_power_up_collisons();
    rocket->update();
}

void GameController::update_enemies(){
    for (auto enemy : enemies){
        add_new_shot_bullets(enemy);
        enemy->update();
        if (check_collison(enemy, rocket)){
            level_running = false;
            game_running = false;
        }
    }
}

void GameController::update_hostages(){
    for (auto hostage : hostages){
        if (check_collison(hostage, rocket)){
            level_running = false;
            game_running = false;
        }
    }
}

void GameController::update_bullets_collisons(){
    vector<Bullet*> bullets_copy = bullets;
    for (auto bullet : bullets_copy)
        update_bullet_collisons(bullet);
}

void GameController::update_rocket_bullet_collisions(Bullet* bullet){
    vector <Enemy*> enemies_copy = enemies;
    for (auto enemy : enemies_copy){
        if (check_collison(enemy, bullet)){
            remove_enemy(enemy);
            remove_bullet(bullet);
        }
    }
    for (auto hostage : hostages){
        if (check_collison(hostage, bullet)){
            game_running = false;
            level_running = false;
        }
    }
}

void GameController::update_enemy_bullet_collisions(Bullet* bullet){
    if(check_collison(rocket, bullet)){
        remove_bullet(bullet);
        if (!rocket->has_power_type(SHIELD)){
            game_running = false;
            level_running = false;
        }
    }
}

void GameController::update_bullet_collisons(Bullet* bullet){
    if (bullet->get_shooter() == ROCKET)
        update_rocket_bullet_collisions(bullet);
    else
        update_enemy_bullet_collisions(bullet);
}

void GameController::remove_bullet(Bullet* bullet){
    auto bullet_index = find(bullets.begin(), bullets.end(), bullet);
    bullets.erase(bullet_index);
    delete bullet;
}

bool GameController::should_make_power_up(){
    return (rand() % 100 + 1 <=  POWER_UP_MAKE_CHANCE);
}

void GameController::make_power_up(Point pos){
    power_ups.push_back(new PowerUp(pos));
}

void GameController::remove_enemy(Enemy* enemy){
    if (level_running && should_make_power_up()){
        make_power_up(enemy->get_position());
    }
    auto enemy_index = find(enemies.begin(), enemies.end(), enemy);
    enemies.erase(enemy_index);
    delete enemy;
}

void GameController::remove_hostage(Hostage* hostage){
    auto hostage_index = find(hostages.begin(), hostages.end(), hostage);
    hostages.erase(hostage_index);
    delete hostage;
}

void GameController::remove_power_up(PowerUp* power_up){
    auto power_up_index = find(power_ups.begin(), power_ups.end(), power_up);
    power_ups.erase(power_up_index);
    delete power_up;
}

void GameController::add_new_shot_bullets(Shooter* shooter){
    vector<Bullet*> new_bullets = shooter->get_new_shot_bullets();
    bullets.insert(bullets.begin(), new_bullets.begin(), new_bullets.end());
}

void GameController::update_power_ups(){
    vector<PowerUp*> power_ups_copy = power_ups;
    for (auto power_up : power_ups_copy){
        power_up->update();
        if (power_up->is_time_finished())
            remove_power_up(power_up);
    }

}

void GameController::draw(){
    window.clear();
    window.draw_img(BACKGROUND_IMG);
    rocket->draw(&window);
    for (auto enemy : enemies)
        enemy->draw(&window);
    for (auto bullet : bullets)
        bullet->draw(&window);
    for (auto hostages : hostages)
        hostages->draw(&window);
    for (auto power_up : power_ups)
        power_up->draw(&window);
    window.update_screen();
}

void GameController::show_msg(string msg){
    window.clear();
    window.show_text(msg, Point(SCREEN_WIDTH/3, SCREEN_HEIGHT/3), WHITE, FONT, MSG_SIZE);
    window.update_screen();
    delay(SHOW_MSG_DELAY);
}

bool check_have_overlap(Rectangle rect1, Rectangle rect2){
    return (rect1.x < rect2.x + rect2.w && rect1.x + rect1.w > rect2.x &&
            rect1.y < rect2.y + rect2.h && rect1.y + rect1.h > rect2.y);
}

bool GameController::is_out_of_screen(GameObject* game_object){
    Rectangle game_object_rect = game_object->get_object_rect();
    Rectangle screen_rect(ORIGIN_POINT , window.get_width(), window.get_height());
    return !check_have_overlap(game_object_rect, screen_rect);
}

bool GameController::check_collison(GameObject* obj1, GameObject* obj2){
    Rectangle obj1_rect = obj1->get_object_rect();
    Rectangle obj2_rect = obj2->get_object_rect();
    return check_have_overlap(obj1_rect, obj2_rect);
}

