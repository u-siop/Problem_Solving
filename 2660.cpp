#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> adj[52];
int n, u, v;
int score[52];

int bfs(int st){
    queue<int> q;
    int dist[52];
    fill(dist, dist+n+1, -1);

    dist[st] = 0;
    q.push(st);

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto fr : adj[cur]){
            if(dist[fr] != -1) continue;
            dist[fr] = dist[cur] + 1;
            q.push(fr);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(u !=-1 && v != -1){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        score[i] = bfs(i);
    }

    int mnscore = *min_element(score+1, score+n+1);
    vector<int> candidate;
    
    for(int i = 1; i <= n; i++){
        if(score[i] == mnscore){
            candidate.push_back(i);
        }
    }

    cout << mnscore << ' ' << candidate.size() << '\n';
    for(auto x : candidate) cout << x << ' ';

    return 0;
}
