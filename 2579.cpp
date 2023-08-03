#include <bits/stdc++.h>
using namespace std;

// time limit : 1sec
// memory limit : 128MB
// MAX starts : 300
// MAX point : 10,000

int n;
int point[302];
int D[302][3];

int main(){
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> point[i];
    }
    if(n == 1){
        cout << point[1] << endl;
        return 0;
    }
    D[1][1] = point[1];
    D[1][2] = 0;
    D[2][1] = point[1] + point[2];
    D[2][2] = point[2];
    // D[3] = max(D[1] + point[3], D[2] + point[3]);
    // D[4] = max(D[2] + point[4], D[3] + point[4]); // what if D[3] is made by D[2] + point[3] and again just one step -> break the rule
    //                                               // need to make an another index that need to jump 2 stairs

    for(int i=3; i<n; i++){
        // if(index[i-1] == 2){
        //     D[i] = D[i-2] + point[i];
        // }
        // if( (D[i-1] + point[i]) == max(D[i-1] + point[i], D[i-2] + point[i]) ){
        //     D[i] = max(D[i-1] + point[i], D[i-2] + point[i]);
        //     index[i]++;
        // }
        D[i][1] = max(D[i-2][1], D[i-1][2]) + point[i];
        D[i][2] = D[i-1][1] + point[i];

    }

    cout << max(D[n][1], D[n][2]) << endl;

    return 0;
}