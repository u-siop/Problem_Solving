#include <bits/stdc++.h>
using namespace std;

// time limit : 0.5 sec
// memory limit : 128MB
// max # of houses : 1,000
// max cost : 1,000

int D[1005][5];
int RGB[1005][5];

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
    }
    D[1][0] = RGB[1][0];
    D[1][1] = RGB[1][1];
    D[1][2] = RGB[1][2];

    // D[2][0] = min(D[1][1], D[1][2]) + RGB[2][0];
    // D[2][1] = min(D[1][0], D[1][2]) + RGB[2][1];
    // D[2][2] = min(D[1][0], D[1][1]) + RGB[2][2];

    // D[3][0] = ...
    // D[3][1]
    // D[3][2] = 
    for(int i=2; i<=n; i++){
        D[i][0] = min(D[i-1][1], D[i-1][2]) + RGB[i][0];
        D[i][1] = min(D[i-1][0], D[i-1][2]) + RGB[i][1];
        D[i][2] = min(D[i-1][0], D[i-1][1]) + RGB[i][2];
    }

    cout << min(min(D[n][0], D[n][1]), D[n][2]) << endl;
    return 0;
}