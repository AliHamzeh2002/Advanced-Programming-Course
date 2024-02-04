#include <iostream>
#include <string>
using namespace std;


bool firstLettersEqual(string str1, string str2){
    return !str1.empty() && !str2.empty() && str1[0] == str2[0];
}

bool areInterleaving(string str1, string str2, string testStr){
    if (str1.empty() && str2.empty() && testStr.empty()){
        return true;
    }
    
    bool returnValue = false;
    if (firstLettersEqual(str1,testStr)){
        returnValue = returnValue || areInterleaving(str1.substr(1), str2, testStr.substr(1));
    } 

    if (firstLettersEqual(str2,testStr)){
        returnValue = returnValue || areInterleaving(str1, str2.substr(1), testStr.substr(1));
    } 
    
    return returnValue;


}
int main(){
    string str1, str2, testStr;
    cin >> str1 >> str2 >> testStr;
    bool result = areInterleaving(str1, str2, testStr);
    if (result){
        cout << "Interleaving";
    }
    else{
        cout << "Not Interleaving";
    }

    return 0;
}