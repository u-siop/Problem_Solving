#include <bits/stdc++.h>
using namespace std;

// time limit : 2sec
// memory limit : 512MB
// N<=100, 1<=K<=100,000, 1<=W<=100,000, V<=1,000

// BF ->2^n 모든 경우의 수 확인, Greedy : 해결 못함, DP : 해결 못함?? -> 0-1 knapsack DP 문제?????
// Make a list which has every possible weights
int dp[105][100005];
int w[105];
int v[105];
vector<int> V;
int main(){
    int n,k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> w[i] >> v[i];
    }
   
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(j-w[i]>=0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout << dp[n][k] << endl;

    return 0;
}