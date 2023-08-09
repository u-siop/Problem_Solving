#include <bits/stdc++.h>
using namespace std;

int S[8][3] = {0, };

int main(){
    int n,k;
    int anw = 0;

    cin >> n >> k;
    for(int i=0; i<n; i++){
        int s, y;
        cin >> s >> y;
        S[y][s]++;
    }

    for(int i=1; i<=6; i++){
        for(int j=0; j<2; j++){
            if(S[i][j] == 0) continue;
            if(S[i][j]%k != 0)    anw += S[i][j]/k + 1;
            else anw +=S[i][j]/k;

        }
    }

    cout << anw << endl;
    return 0;
}