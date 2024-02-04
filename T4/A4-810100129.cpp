#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const string COUNTER_TERRORIST = "counter-terrorist";
const string TERRORIST = "terrorist";
const string START_COMMAND = "start";
const string START_FIGHT_MSG = "fight!";
const string ADD_USER_COMMAND = "add-user";
const string ADD_USER_DONE_MSG = "ok";
const string GET_MONEY_COMMAND = "get-money";
const string GET_HEALTH_COMMAND = "get-health";
const string GO_AFK_COMMAND = "go-afk";
const string GO_ATK_COMMAND = "go-atk";
const string AFK_MODE_ACTIVATED_MSG = "ok";
const string ATK_MODE_ACTIVATED_MSG = "ok";
const string ROUND_COMMAND = "round";
const string BUY_COMMAND = "buy";
const string HEAVY_GUN_NAME = "heavy";
const string PISTOL_NAME = "pistol";
const string KNIFE_NAME = "knife";
const string CANT_BUY_MSG = "you can't buy weapons anymore";
const string NOT_FOUND_USER = "not_found";
const string USER_NOT_AVAILABLE_MSG = "user not available";
const string ALREADY_HAVE_WEAPON_MSG = "you already have this weapon";
const string NOT_ENOUGH_MONEY_MSG = "insufficient money";
const string WEAPON_BOUGHT_MSG = "weapon bought successfully";
const string SHOOT_COMMAND = "shoot";
const string ATTACKER_DEAD_MSG = "attacker is dead";
const string ATTACKED_DEAD_MSG = "attacked is dead";
const string NOT_HAVE_WEAPON_MSG = "attacker doesn't have this gun";
const string CANT_SHOOT_TEAMMATE_MSG = "you can't shoot this player";
const string SHOT_DONE_MSG = "nice shot";
const string GAME_NOT_STARTED_MSG = "The game hasn't started yet";
const string CT_WIN_MSG = "counter-terrorist won";
const string TERROR_WIN_MSG = "terrorist won";
const string SCORE_BOARD_COMMAND = "score-board";
const string PLAYERS = "players";
const char SPACE = ' ';
const char COLON = ':';
const bool BEFORE_START = true;
const bool AFTER_START = false;
const int INIT_HEALTH = 100;
const int NOT_FOUND = -1;
const int NOT_FOR_SALE = -1;
const int HEAVY_GUN_PRICE = 3000;
const int HEAVY_GUN_DAMAGE = 45;
const int HEAVY_GUN_KILL_BONUS = 100;
const int PISTOL_PRICE = 400;
const int PISTOL_DAMAGE = 20;
const int PISTOL_KILL_BONUS = 200;
const int KNIFE_PRICE = NOT_FOR_SALE;
const int KNIFE_DAMAGE = 35;
const int KNIFE_KILL_BONUS = 500;
const int WINNER_REWARD = 2700;
const int LOSER_REWARD = 2400;
const int MAX_MONEY = 10000;
const int INITIAL_MONEY = 1000;


class Weapon{
    public:
        Weapon();
        Weapon(string _name, int init_price, int init_damage, int  init_kill_bonus);
        string get_name(){return name;}
        int get_price(){return price;}
        int get_damage(){return damage;}
        int get_kill_bonus(){return kill_bonus;}
    private:
        string name;
        int price;
        int damage;
        int kill_bonus;
};

typedef vector<Weapon> WeaponList;

const Weapon HEAVY_GUN = Weapon(HEAVY_GUN_NAME, HEAVY_GUN_PRICE, HEAVY_GUN_DAMAGE, HEAVY_GUN_KILL_BONUS);
const Weapon PISTOL = Weapon(PISTOL_NAME, PISTOL_PRICE, PISTOL_DAMAGE, PISTOL_KILL_BONUS);
const Weapon KNIFE = Weapon(KNIFE_NAME, KNIFE_PRICE, KNIFE_DAMAGE, KNIFE_KILL_BONUS);
const WeaponList AVAILABLE_WEAPONS = {HEAVY_GUN, PISTOL, KNIFE};

class Player{
    public:
        Player(string _username, string init_team, int init_health = INIT_HEALTH, int init_money = INITIAL_MONEY,
              bool init_attack_permission = true);
        string get_username(){return username;}
        string get_team(){return team;}
        int get_health(){return health;}
        int get_money(){return money;}
        int get_kills(){return kills;}
        int get_deaths(){return deaths;}
        bool get_attack_permission(){return attack_permission;}
        bool check_has_weapon(string weapon_name);
        bool is_dead();
        void lose_health(int damage_taken);
        void inc_deaths();
        void inc_kills();
        void gain_money(int gained_money);
        void lose_weapons();
        void go_afk_mode();
        void go_atk_mode();
        void heal();
        void shoot(Player* attacked, Weapon used_weapon);
        void add_weapon(Weapon weapon);
        void spend_money(int spent_money);
    private:
        string username;
        string team;
        int health;
        int money;
        int kills;
        int deaths;
        bool attack_permission;
        WeaponList weapons_list;
};

Player* PLAYER_NOT_FOUND = NULL;

typedef vector<Player*> PlayerList;

class GameController{
    public:
        GameController();
        void input_number_of_rounds();
        void game_loop();
        void handle_add_user();
        void handle_round();
        void handle_get_health();
        void handle_get_money();
        void handle_start();
        void handle_go_afk();
        void handle_go_atk();
        void handle_buy();
        void handle_shoot();
        void reset_players();
        void show_score_board();
        void show_team_stats(string team_name, PlayerList team);
        void show_round_result(string winner);
        void give_round_rewards(string winner);
        void add_weapon(Weapon weapon);
        bool can_player_participate(Player* player);
        int calc_active_players(PlayerList team_list);
        Player* find_player_by_name(string username);
        Weapon find_weapon_by_name(string weapon_name);
        string calc_round_winner();
    private:
        PlayerList counter_terrorist_players;
        PlayerList terrorist_players;
        WeaponList game_weapons;
        int number_of_rounds;
        int game_status;
};

Weapon::Weapon(string _name, int init_price, int init_damage, int  init_kill_bonus){
    name = _name;
    price = init_price;
    damage = init_damage;
    kill_bonus = init_kill_bonus;
}

Player::Player(string _username,string init_team, int init_health, int init_money, bool init_attack_permission){
    username = _username;
    health = init_health;
    money = init_money;
    team = init_team;
    attack_permission = init_attack_permission;
    weapons_list = {KNIFE};
}

void Player::lose_health(int damage_taken){
    health -= damage_taken;
    if (health < 0)
        health = 0;
}

void Player::inc_deaths(){
    deaths++;
}

void Player::inc_kills(){
    kills++;
}

void Player::gain_money(int gained_money){
    money += gained_money;
    if (money > MAX_MONEY)
        money = MAX_MONEY;
}

void Player::heal(){
    health = 100;
}

void Player::lose_weapons(){
    weapons_list.clear();
    weapons_list.push_back(KNIFE);
}

void Player::shoot(Player* attacked,Weapon used_weapon){
    attacked->lose_health(used_weapon.get_damage());
    if (attacked->is_dead()){
        attacked->inc_deaths();
        attacked->lose_weapons();
        inc_kills();
        gain_money(used_weapon.get_kill_bonus());
    }
}

bool Player::is_dead(){
    return !get_health();
}

bool Player::check_has_weapon(string weapon_name){
    for (auto weapon : weapons_list){
        if (weapon_name == weapon.get_name())
            return true;
    }
    return false;
}

void Player::go_afk_mode(){
    attack_permission = false;
}

void Player::go_atk_mode(){
    attack_permission = true;
}

void Player::add_weapon(Weapon weapon){
    weapons_list.push_back(weapon);
}

void Player::spend_money(int spent_money){
    money -= spent_money;
}

GameController::GameController(){
    game_status = BEFORE_START;
    game_weapons = AVAILABLE_WEAPONS;
}

int GameController::calc_active_players(PlayerList team_list){
    int active_players = 0;
    for (auto player:team_list){
        if (player->get_attack_permission() && !player->is_dead())
            active_players++;
    }
    return active_players;
}

string GameController::calc_round_winner(){
    int terrorist_remainings = calc_active_players(terrorist_players);
    int ct_remainings = calc_active_players(counter_terrorist_players);
    if (ct_remainings == 0)
        return TERRORIST;
    return COUNTER_TERRORIST; 
}

void GameController::give_round_rewards(string winner){
    int t_reward = WINNER_REWARD;
    int ct_reward = LOSER_REWARD;
    if (winner == COUNTER_TERRORIST)
        swap(t_reward,ct_reward);
    for (auto player:terrorist_players)
        player->gain_money(t_reward);
    for (auto player:counter_terrorist_players)
        player->gain_money(ct_reward);
}

void GameController::show_round_result(string winner){
    if (winner == COUNTER_TERRORIST)
        cout << CT_WIN_MSG << endl;
    else
        cout << TERROR_WIN_MSG << endl;
}

void GameController::input_number_of_rounds(){
    cin >> number_of_rounds;
}

Weapon GameController::find_weapon_by_name(string weapon_name){
    for (auto weapon : game_weapons){
        if (weapon_name == weapon.get_name())
            return weapon;
    }
}

void GameController::handle_get_money(){
    string username;
    cin >> username;
    Player* wanted_player = find_player_by_name(username);
    cout << wanted_player->get_money() << endl;
}

void GameController::handle_get_health(){
    string username;
    cin >> username;
    Player* wanted_player = find_player_by_name(username);
    cout << wanted_player->get_health() << endl;
}

void GameController::handle_start(){
    cout << START_FIGHT_MSG << endl;
    game_status = AFTER_START;
}

void GameController::handle_go_afk(){
    string username;
    cin >> username;
    Player* wanted_player = find_player_by_name(username);
    wanted_player->go_afk_mode();
    cout << AFK_MODE_ACTIVATED_MSG << endl;
}

void GameController::handle_go_atk(){
    string username;
    cin >> username;
    Player* wanted_player = find_player_by_name(username);
    wanted_player->go_atk_mode();
    cout << ATK_MODE_ACTIVATED_MSG << endl;
}

bool GameController::can_player_participate(Player* player){
    return (player != PLAYER_NOT_FOUND && player->get_attack_permission());
}

void GameController::handle_shoot(){
    string attacker_name;
    string attacked_name;
    string used_weapon_name;
    cin >> attacker_name >> attacked_name >> used_weapon_name;
    Player* attacker = find_player_by_name(attacker_name);
    Player* attacked = find_player_by_name(attacked_name);
    Weapon used_weapon = find_weapon_by_name(used_weapon_name);
    if (!can_player_participate(attacked) || !can_player_participate(attacker))
        cout << USER_NOT_AVAILABLE_MSG << endl;
    else if (attacker->is_dead())
        cout << ATTACKER_DEAD_MSG << endl;
    else if (attacked->is_dead())
        cout << ATTACKED_DEAD_MSG << endl;
    else if(!attacker->check_has_weapon(used_weapon_name))
        cout << NOT_HAVE_WEAPON_MSG << endl;
    else if(attacked->get_team() == attacker->get_team())
        cout << CANT_SHOOT_TEAMMATE_MSG << endl;
    else if(game_status == BEFORE_START)
        cout << GAME_NOT_STARTED_MSG << endl;
    else{ 
        attacker->shoot(attacked, used_weapon);
        cout << SHOT_DONE_MSG << endl;
    }
}

void GameController::handle_buy(){
    string username;
    string weapon_name;
    cin >> username >> weapon_name;
    Player* wanted_player = find_player_by_name(username);
    Weapon weapon = find_weapon_by_name(weapon_name);
    if (game_status == AFTER_START)
        cout << CANT_BUY_MSG << endl;
    else if (!can_player_participate(wanted_player))
        cout << USER_NOT_AVAILABLE_MSG << endl;
    else if (wanted_player->check_has_weapon(weapon_name))
        cout << ALREADY_HAVE_WEAPON_MSG << endl;
    else if (weapon.get_price() > wanted_player->get_money())
        cout << NOT_ENOUGH_MONEY_MSG << endl;
    else{
        wanted_player->add_weapon(weapon);
        wanted_player->spend_money(weapon.get_price());
        cout << WEAPON_BOUGHT_MSG << endl;
    }
}

void GameController::reset_players(){
    for (auto player:terrorist_players)
        player->heal();
    for (auto player:counter_terrorist_players)
        player->heal();
}

void GameController::handle_round(){
    game_status = BEFORE_START;
    int number_of_commands;
    cin >> number_of_commands;
    string command;
    for (int i = 0; i < number_of_commands; i++){
        cin >> command;
        if (command == GET_HEALTH_COMMAND)
            handle_get_health();
        else if (command == GET_MONEY_COMMAND)
            handle_get_money();
        else if (command == GO_AFK_COMMAND)
            handle_go_afk();
        else if (command == GO_ATK_COMMAND)
            handle_go_atk();
        else if (command == START_COMMAND)
            handle_start();
        else if (command == BUY_COMMAND)
            handle_buy();
        else if(command == SHOOT_COMMAND)
            handle_shoot();
        else if (command == SCORE_BOARD_COMMAND)
            show_score_board();   
    }
    string winner = calc_round_winner();
    give_round_rewards(winner); 
    show_round_result(winner);
    reset_players();
}

bool compare_players(Player* p1, Player* p2){
    return (p1->get_kills() > p2->get_kills() || 
            (p1->get_kills() == p2->get_kills() && p1->get_deaths() < p2->get_deaths()) ||
            (p1->get_kills() == p2->get_kills() && p1->get_deaths() == p2->get_deaths() 
            && p1->get_username() < p2->get_username()));
}

void GameController::show_team_stats(string team_name, PlayerList team){
    cout << team_name << SPACE << PLAYERS << COLON << endl;
    for (auto player:team)
        cout << player->get_username() << SPACE << player->get_kills() << SPACE << player->get_deaths() << endl;
}

void GameController::show_score_board(){
    sort(terrorist_players.begin(), terrorist_players.end(), compare_players);
    sort(counter_terrorist_players.begin(), counter_terrorist_players.end(), compare_players);
    show_team_stats(COUNTER_TERRORIST, counter_terrorist_players);
    show_team_stats(TERRORIST, terrorist_players);
}

void GameController::game_loop(){
    string command;
    while (cin >> command){
        if (command == ADD_USER_COMMAND)
            handle_add_user();
        if (command == ROUND_COMMAND)
            handle_round();  
        if (command == SCORE_BOARD_COMMAND)
            show_score_board();      
    }
}

Player* GameController::find_player_by_name(string username){
    for (auto player:terrorist_players){
        if (player->get_username() == username)
            return player;
    }
    for (auto player:counter_terrorist_players){
        if (player->get_username() == username)
            return player;
    }
    return PLAYER_NOT_FOUND;
}

void GameController::handle_add_user(){
    string username;
    string team;
    cin >> username;
    cin >> team;
    if (team == COUNTER_TERRORIST)
        counter_terrorist_players.push_back(new Player(username, team));
    else
        terrorist_players.push_back(new Player(username, team));
    cout << ADD_USER_DONE_MSG << endl;
}

int main(){
    GameController game_controller;
    game_controller.input_number_of_rounds();
    game_controller.game_loop();

    return 0;
}