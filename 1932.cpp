#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int tri[502][502];
int dp[502][502];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cin >> tri[i][j];
        }
    }

    dp[0][0] = tri[0][0];

    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i-1][0] + tri[i-1][0];
    }
    for(int i = 1; i < n; i++){
        dp[i][i] = dp[i-1][i] + tri[i-1][i];
    }
    // dp[i][j] = max(dp[i-1][j] + tri[i-1][j] or dp[i-1][j+1] + tri[i-1][j+1])
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n-1; j++)
        {
            dp[i][j] = max(dp[i-1][j] + tri[i-1][j], dp[i-1][j+1] + tri[i-1][j+1]);
        }
    }

    cout << *max_element(dp[n], dp[n]+n);

    return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;

int n;
int a[505][505], d[505][505];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= i; ++j)
      cin >> a[i][j];
  d[1][1] = a[1][1];
  for(int i = 2; i <= n; ++i)
    for(int j = 1; j <= i; ++j)
      d[i][j] = max(d[i-1][j-1], d[i-1][j]) + a[i][j];
  cout << *max_element(d[n] + 1, d[n] + n + 1);
}

*/
