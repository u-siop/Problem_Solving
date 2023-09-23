#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<int> adj[32010];
    queue<int> q;
    int deg[32010];

    for(int i = 0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }
    
    for(int i=1; i<=n; i++){
        if(deg[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for(auto nxt: adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }

    // if(result.size() != n) cout << "cycle exits\n";
        // for(auto x: result) cout << x << ' ';
    
    return 0;
}