#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int v, e;
int ans = 0;
vector<int> adj[102];
int vis[102];

void dfs(int cur){
    vis[cur] = 1;
    for(auto nxt: adj[cur]){
        if(vis[cur]) continue;
        ans++;
        dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;

    for(int i=0; i<e; i++){
        int a,b;

        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    cout << ans << '\n';

    return 0;
}