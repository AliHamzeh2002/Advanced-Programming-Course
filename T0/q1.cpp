#include <iostream>
using namespace std;

int main(){
    long long int n, m , profit;
    cin >> n >> m;
    m *= 100;
    for (int i = 0 ; i < n ; i++){
        int x,y,z;
        cin >> x >> y >> z;
        profit += (x*y*z);
    }
    if (profit>=m) cout<<"YES";
    else cout<< "NO";
    

}
