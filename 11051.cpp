#include <bits/stdc++.h>
using namespace std;

// time limit : 1sec
// memory limit :256MB
typedef long long ll;
ll dp[1005][1005];
int main(){
    int n,k;
    cin >> n >> k;          // nCk = n! / (n-k)! k!    , 0C0 = 1, nCn = 1
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j==0) dp[i][0] =1;
            else if(j==i) dp[i][j] = 1;
            else dp[i][j] = ( dp[i-1][j-1] + dp[i-1][j] )% 10007;
        }
    }

    cout << dp[n][k] <<endl;

    return 0;
}