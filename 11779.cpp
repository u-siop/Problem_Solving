#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1e9+10;

int v, e, st ,en;
vector<pair<int, int>> adj[1005];
int d[1005];
int pre[1005];

int main(){
    cin >> v >> e;
    fill(d,d+v+1,INF);

    while(e--){
        int u, v, w;

        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    int st, en;
    cin >> st >> en;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[st] = 0;
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.second] != cur.first) continue;
        for(auto nxt : adj[cur.second]){
            if(d[nxt.second] <= d[cur.second] + nxt.first) continue;
            d[nxt.second] = d[cur.second] + nxt.first;
            pq.push({d[nxt.second], nxt.second});
            pre[nxt.second] = cur.second;
        }
    }

    cout << d[en] << '\n';

    vector<int> path;
    int cur = en;
    while(cur != st){
        path.push_back(cur);
        cur = pre[cur];
    }

    path.push_back(cur);
    reverse(path.begin(), path.end());
    cout << path.size() << '\n';

    for(auto x : path) cout << x << ' ';

    return 0;
}
