#include <iostream>
#include <vector>

using namespace std;

const int POSSIBLE_MOVES = 4;

struct Dimensions{
    int width;
    int height;
};

typedef vector<int> FarmRow;

long int calc_row_sum(Dimensions farm_dimensions, vector<FarmRow> farm, int row_index){
    long int sum = 0;
    for (int i = 0; i < farm_dimensions.width; i++){
        sum += farm[row_index][i];
    }
    return sum;
}

int find_max_row_index(Dimensions farm_dimensions, vector<FarmRow> farm){
    long int max_row = 0;
    int max_row_index = 0;
    for(int row_index = 0; row_index < farm_dimensions.height; row_index++){
        long int row_sum = calc_row_sum(farm_dimensions, farm, row_index);
        if(row_sum > max_row){
            max_row = row_sum;
            max_row_index = row_index;
        }
    }
    return max_row_index;
}

long int calc_col_sum(Dimensions farm_dimensions, vector<FarmRow> farm, int col_index){
    long int sum = 0;
    for (int i = 0; i < farm_dimensions.height; i++){
        sum += farm[i][col_index];
    }
    return sum;
}

int find_max_col_index(Dimensions farm_dimensions, vector<FarmRow> farm){
    long int max_column = 0;
    int max_col_index = 0;
    for(int col_index = 0; col_index < farm_dimensions.width; col_index++){
        long int col_sum = calc_col_sum(farm_dimensions, farm, col_index);
        if(col_sum > max_column){
            max_column = col_sum;
            max_col_index = col_index;
        }
    }
    return max_col_index;
}

vector<FarmRow> empty_column(Dimensions farm_dimensions, vector<FarmRow> farm, int col_index){
    for(int i = 0; i < farm_dimensions.height; i++)
        farm[i][col_index] = 0;
    return farm;
}

vector<FarmRow> empty_row(Dimensions farm_dimensions, vector<FarmRow> farm, int row_index){
    for(int i = 0; i < farm_dimensions.width; i++)
        farm[row_index][i] = 0;
    return farm;
}

long int calc_max_harvest(Dimensions farm_dimensions, vector<FarmRow> farm){
    long int max_harvest = 0;
    for(int move = 0; move < POSSIBLE_MOVES; move++){
        int max_row_index = find_max_row_index(farm_dimensions, farm);
        long int max_row = calc_row_sum(farm_dimensions, farm, max_row_index);
        int max_col_index = find_max_col_index(farm_dimensions, farm);
        long int max_col = calc_col_sum(farm_dimensions, farm, max_col_index);
        if(max_col > max_row){
            max_harvest += max_col;
            farm = empty_column(farm_dimensions, farm, max_col_index);
        }
        else{
            max_harvest += max_row;
            farm = empty_row(farm_dimensions, farm, max_row_index);
        }
    }
    return max_harvest;
}

Dimensions get_farm_dimensions(){
    Dimensions farm_dimensions;
    cin >> farm_dimensions.height >> farm_dimensions.width;
    return farm_dimensions;
}

vector<FarmRow> get_farm_products(Dimensions farm_dimensions){    
    vector<FarmRow> farm(farm_dimensions.height, FarmRow(farm_dimensions.width));
    int product;
    for(int i = 0; i < farm_dimensions.height; i++){
        for(int j = 0; j < farm_dimensions.width; j++){
            cin >> product;
            farm[i][j] = product;
        }
    }
    return farm;
}

int main() {
    Dimensions farm_dimensions = get_farm_dimensions();
    vector<FarmRow> farm = get_farm_products(farm_dimensions);
    long int max_harvest = calc_max_harvest(farm_dimensions, farm);
    cout << max_harvest;
    return 0;
} 