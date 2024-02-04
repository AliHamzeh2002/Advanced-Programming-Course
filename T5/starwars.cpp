#include "GameController.hpp"

using namespace std;

int main(int argc, char* argv[]){
    string map_file_name = argv[1];
    GameController game_controller(map_file_name);
    game_controller.run_game();
    return 0;
}