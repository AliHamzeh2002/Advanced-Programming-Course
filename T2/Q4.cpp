#include <iostream>
#include <vector>
using namespace std;
bool canMakeWeight(int goal, vector<int>& weights, int vectorIndex = 0, int weightSum = 0){
    if (weightSum == goal){
        return true;
    }
    if (vectorIndex == weights.size()){
        return false;
    }
    int currentWeight = weights[vectorIndex];
    return (canMakeWeight(goal, weights, vectorIndex + 1, weightSum + currentWeight) ||
            canMakeWeight(goal, weights, vectorIndex + 1, weightSum - currentWeight) ||
            canMakeWeight(goal, weights, vectorIndex + 1, weightSum));
}

vector<int> getWeights(int numberOfWeights){
    vector<int> weights(numberOfWeights);
    for (int i = 0 ; i < numberOfWeights ; i++){
        cin >> weights[i];
    }
    return weights;
}
int main(){
    int numberOfWeights, goal;
    cin >> numberOfWeights >> goal;
    vector<int> weights = getWeights(numberOfWeights);
    if (canMakeWeight(goal, weights)){
        cout << "True";
    }
    else{
        cout << "False";
    }


}