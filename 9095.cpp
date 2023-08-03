#include <bits/stdc++.h>
using namespace std;
int D[15];

int main(){
    int t;
    int n;

    D[1] = 1;
    D[2] = 2;
    D[3] = 4;
    for(int i=4; i<=11; i++){
        D[i] = D[i-1] + D[i-2] + D[i-3] ;      // n[4] == 12? but actually n[4] == 7  n[5] ?
    }

    cin >> t;
    while(t--){
        cin >> n;
        cout << D[n] << endl;
    }

    return 0;
}