#include <iostream>
#include <math.h>
using namespace std;

int main(){
    long long int n, m, s, profit;
    profit = 0;
    cin>>n>>m>>s;
    m *= 100;
    long long int items[100][4];
    for (int i = 0 ; i < n ; i++){
        long long int x,y,z;
        cin >> x >> y >> z;
        if (y>s) y=s;
        profit += (x*y*z);
        items[i][0] = x;
        items[i][1] = y;
        items[i][2] = z;
        items[i][3] = 0;
    }

    long long int remaining = m - profit;
    if (remaining > 0 ){
        for (int i = 0 ; i<n ; i++){
            int max_index = -1;
            for (int j = 0 ; j<n ; j++){
                if ((items[j][3]==0 && max_index == -1) || (items[j][3]==0 && items[j][0]*items[j][2] > items[max_index][0]*items[max_index][2])){
                    max_index = j;
                }
            }
            long long int* item = items[max_index];
            item[3] = 1;
            if (item[0]*(s-item[1])*item[2] < remaining){
                remaining -= item[0]*(s-item[1])*item[2];
                item[1] = s;
            }
            else{
                item[1] = ceil(item[1] + (double)remaining/(item[0]*item[2]));
                remaining = 0;
                break;
            }
        }
    }
    if (remaining>0){
        cout<<"NOT_POSSIBLE";
    }
    else{
        for (int i = 0 ; i<n;i++){
            cout<<items[i][1]<<endl;
        }
    }

}

