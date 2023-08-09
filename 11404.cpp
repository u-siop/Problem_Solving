#include <bits/stdc++.h>
using namespace std;

// time limit : 1sec
// memory limit : 256MB
// 2<=n<=100, 1<=m<=100,000

const int INF = 0x3f3f3f3f;

int main(){
    int n,m;
    cin >> n >> m;
    int f[105][105];
    for(int i=1; i<=n; i++)
        fill(f[i], f[i]+1+n, INF);
    for(int i=0; i<m; i++){
        int c,r,cost;
        cin >> c >> r >> cost;
        f[c][r] = min(f[c][r], cost);
    }

    for(int i=1; i<=n; i++){
        f[i][i] = 0;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(f[i][j] == INF) cout<<"0 ";
            else cout << f[i][j] <<' ';
        }
        cout << '\n';
    }

    return 0;
}