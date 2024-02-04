#include <iostream>
#include <string>
using namespace std;

const string INIT_STRING = "0";
const string ZERO_CONVERT = "01";
const string ONE_CONVERT = "10";
const string EMPTY = "";

string calculateBinaryString(string initString, int level){
    if (level <= 1){
        return initString;
    }
    string resultString = EMPTY;
    for (char stringChar : initString){
        if (stringChar == '0'){
            resultString += calculateBinaryString(ZERO_CONVERT,level - 1);
        }
        else{
            resultString += calculateBinaryString(ONE_CONVERT,level - 1);
        }
    }
    return resultString;

}
int main(){
    int level,bitNumber;
    cin >> level >> bitNumber;
    cout << calculateBinaryString(INIT_STRING, level)[bitNumber - 1]; 


    return 0;
}