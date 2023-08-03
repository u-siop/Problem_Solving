#include <bits/stdc++.h>
using namespace std;

int D[1005][5];
int RGB[1005][5];

int main(){
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
    }
    D[1][1] = min(min(RGB[1][0], RGB[1][1]), RGB[1][2]);

    D[2][1] = min(min(RGB[2][0], RGB[2][1]), RGB[2][2]);

    D[]

    return 0;
}