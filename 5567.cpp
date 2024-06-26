// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>
// using namespace std;

// int n, m, ans = 0;
// int num = 0;

// vector<int> adj[505];
// vector<int> cnt[505];
// queue<int> Q;

// void bfs(){
//     while(!Q.empty()){
//         int cur = Q.front(); Q.pop();
//         int l = adj[cur].size();
//         for(int i = 0; i < l; i++){
//             Q.push(adj[cur][i]);
//             cnt[cur].push_back(num);
//         }
//     }
//     num++;
// }

// int main(){
//     cin >> n >> m;
//     for(int i = 0; i < m; i++){
//         int a,b;
//         cin >> a >> b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }
//     Q.push(1);

//     // bfs로 상근으로부터 친구 거리 재기
//     bfs();
//     // 거리 2이하인 사람 count
//     for(int i = 0; i < n; i++){
//         if(cnt[cur])
//     }
//     cout << ans << "\n";
// }

#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector <int> adj[505];
int vis[505];
int ans = 0;

void dfs(){
  stack<int> s;
  s.push(1);
  while(!s.empty()){
    int cur = s.top(); s.pop();
    vis[cur] = 1;
    for(auto nxt : adj[cur]){
      if(vis[nxt]) continue;
      vis[nxt] = 1;
      ans++;
      if(cur == 1) s.push(nxt); // 상근이의 이웃만 스택에 추가됨
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while(m--){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs();
  cout << ans;
}