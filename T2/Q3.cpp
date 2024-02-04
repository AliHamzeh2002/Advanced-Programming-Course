#include <iostream>
#include <vector>
#include <string>
using namespace std;

const char ROCK = '#';
const char BAMBOO = '*';
const char NORMAL_PATH = '.';
const bool VISITED = true;
const bool NOT_VISITED = false;
const int UP_INDEX = 0;
const int RIGHT_INDEX = 1;
const int LEFT_INDEX = 2;
const int DOWN_INDEX = 3;
const int NOT_MEASURED = -1;
const int INITIAL_ROW = 0;
const int INITIAL_COL = 0;

typedef struct Direction{
    int y;
    int x;
} Direction;

const Direction RIGHT = {0,1};
const Direction LEFT = {0,-1};
const Direction UP = {-1,0};
const Direction DOWN = {1,0};

int getNextRow(int row, Direction direction){
    return row + direction.y;
}

int getNextCol(int column, Direction direction){
    return column + direction.x;
}

bool directionsEqual(Direction direction1, Direction direction2){
    return (direction1.x == direction2.x && direction1.y == direction2.y);
}

int getDirectionIndex(Direction direction){
    if (directionsEqual(RIGHT,direction)){
        return RIGHT_INDEX;
    }
    else if (directionsEqual(LEFT,direction)){
        return LEFT_INDEX;
    }
    else if (directionsEqual(UP,direction)){
        return UP_INDEX;
    }
    else {
        return DOWN_INDEX;
    }
}

bool checkVisited(int row, int col, Direction direction, 
                vector<vector<vector<bool>>>& visitedPosDirs){
    int index = getDirectionIndex(direction);
    return visitedPosDirs[row][col][index];
    }

bool canMoveWithDirection(int row, int column, Direction direction, vector<string> map,
            vector<vector<vector<bool>>>& visitedPosDirs){
    int nextRow = getNextRow(row, direction);
    int nextCol = getNextCol(column, direction);
    return !(nextRow >= map.size() || nextRow < 0 || nextCol >= map[0].size() ||
            nextCol < 0 || map[nextRow][nextCol] == ROCK ||
            checkVisited(nextRow,nextCol,direction,visitedPosDirs));
}

vector<Direction> getNewDirections(Direction currentDirection){
    vector<Direction> returnVector;
    if (directionsEqual(currentDirection,UP) || directionsEqual(currentDirection,DOWN)){
        returnVector.push_back(LEFT);
        returnVector.push_back(RIGHT);
    }
    else{
        returnVector.push_back(UP);
        returnVector.push_back(DOWN);
    }
    return returnVector;
}

int getShortestMovesFromData(int row, int col, Direction direction,
     vector<vector<vector<int>> > shortestMovesFromPosDirs){
    int directionIndex = getDirectionIndex(direction);
    return shortestMovesFromPosDirs[row][col][directionIndex];
}

void changeVisited(int row, int col, Direction direction, 
                    vector<vector<vector<bool>> >& visitedPosDirs, bool change){
    int index = getDirectionIndex(direction);
    visitedPosDirs[row][col][index] = change;
}

void changeShortestMovesData(int row, int col, Direction direction,
                        vector<vector<vector<int>> >& shortestMovesFromPosDirs, int newMovesNumber){
    int index = getDirectionIndex(direction);
    shortestMovesFromPosDirs[row][col][index] = newMovesNumber;                   
}

int maxPossiblePath(vector<string> map){
    return map.size() * map[0].size();
}

int findShortestPath(int row, int column, Direction direction,vector<string> map,
                     vector<vector<vector<int>>>& shortestMovesFromPosDirs, vector<vector<vector<bool>>>& visitedPosDirs ){
    const int NO_PATH = maxPossiblePath(map) + 1;
    char currentPos = map[row][column];
    if (checkVisited(row, column, direction, visitedPosDirs)){
        return NO_PATH;
    }
    if (currentPos == BAMBOO){
        return 0;
    }
    int movesFromData = getShortestMovesFromData(row, column, direction, shortestMovesFromPosDirs);
    if (movesFromData != NOT_MEASURED){
        return movesFromData;
    } 
    changeVisited(row, column, direction, visitedPosDirs, VISITED);
    int shortestMoves = NO_PATH;
    if (canMoveWithDirection(row, column, direction, map,visitedPosDirs)){
        int nextRow = getNextRow(row, direction);
        int nextCol = getNextCol(column, direction);
        int nextMoves = findShortestPath(nextRow, nextCol, direction, map, shortestMovesFromPosDirs, visitedPosDirs);
        if (nextMoves != NO_PATH){
            shortestMoves = nextMoves + 1;
        }
    }
    else{
        vector<Direction> newDirections = getNewDirections(direction);
        Direction newDirection1 = newDirections[0];
        int moveNumbers1 = findShortestPath(row, column, newDirection1, map, shortestMovesFromPosDirs, visitedPosDirs);
        Direction newDirection2 = newDirections[1];
        int moveNumbers2 = findShortestPath(row, column, newDirection2, map, shortestMovesFromPosDirs, visitedPosDirs);
        shortestMoves = min(moveNumbers1,moveNumbers2);
    }
    changeShortestMovesData(row, column, direction, shortestMovesFromPosDirs, shortestMoves);
    changeVisited(row, column, direction, visitedPosDirs, NOT_VISITED);
    return shortestMoves;
}

vector<string> getMapInput(){
    vector<string> map;
    string row; 
    while (cin >> row){
        map.push_back(row);
    }
    return map;
}

void handleOutput(int shortestPathFromDownDir, int shortestPathFromRightDir, vector<string> map){
    const int NO_PATH = maxPossiblePath(map) + 1;
    if (shortestPathFromDownDir == NO_PATH && shortestPathFromRightDir == NO_PATH){
        cout << "No path found";
    }
    else{
        cout << min(shortestPathFromDownDir,shortestPathFromRightDir);
    }
}
vector<vector<vector<int>>> initializeShortestMovesVector(vector<string> map){
    vector<vector<vector<int>> > shortestMovesFromPosDirs;
    for (int i = 0 ; i < map.size() ; i++){
        vector<vector<int>> nextRow;
        for (int j = 0 ; j<map[0].size();j++){
            vector<int> shortestMoves(4,NOT_MEASURED);
            nextRow.push_back(shortestMoves);
        }
        shortestMovesFromPosDirs.push_back(nextRow);
    }
    return shortestMovesFromPosDirs;
}
vector<vector<vector<bool>>> initializeVisitedVector(vector<string> map){
    vector<vector<vector<bool>> > visitedPosDirs;
    for (int i = 0; i < map.size(); i++){
        vector<vector<bool>> nextRow;
        for (int j = 0 ; j<map[0].size();j++){
            vector<bool> visitedDirections(4,NOT_VISITED);
            nextRow.push_back(visitedDirections);
        }
    visitedPosDirs.push_back(nextRow);
    }  
    return visitedPosDirs;
}

int main(){
    vector<string> map = getMapInput();
    vector<vector<vector<bool>>> visitedPosDirs = initializeVisitedVector(map);
    vector<vector<vector<int>>> shortestMovesFromPosDirs = initializeShortestMovesVector(map);
    int shortestPathFromRightDir = findShortestPath(INITIAL_ROW,INITIAL_COL,RIGHT,
    map,shortestMovesFromPosDirs,visitedPosDirs);
    int shortestPathFromDownDir = findShortestPath(INITIAL_ROW,INITIAL_COL,DOWN,
    map,shortestMovesFromPosDirs,visitedPosDirs);
    handleOutput(shortestPathFromDownDir, shortestPathFromRightDir, map);
    return 0;
}