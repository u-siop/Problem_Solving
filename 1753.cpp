#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[20005];
int d[200005];

const int INF = 1e9+10;
int v,e,k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(d,d+v+1,INF);

    cin >> v >> e;
    cin >> k;


    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[k] = 0;
    pq.push({d[k], k});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.second] != cur.first) continue;
        for(auto nxt : adj[cur.second]){
            if(d[nxt.second] <= d[cur.second] + nxt.first) continue;
            d[nxt.second] = d[cur.second] + nxt.first;
            pq.push({d[nxt.second], nxt.second});
        }
    }

    for(int i = 1; i <= v; i++){
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << '\n';
    }


    return 0;
}