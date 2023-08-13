#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
queue<int> q;
stack<int> s;
bool visited[1005];
int n, m;
// list<int> adj[1005];

// void bfs(){
//     for(int i=1; i<=m; i++){
//         list<int>::iterator iter = adj[i].begin();
//         for(iter = adj[i].begin(); iter!=adj[i].end(); iter++){
//             if(visited[i][*iter] == 1) continue;
//             visited[i][*iter] = 1;
//             q.push({i,*iter});
//         }
//     }
// }

void bfs(){
    int num = 0;
    for(int i=1; i<=n; i++){
        if(visited[i] == 1) continue;
        num++;
        q.push(i);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto nxt : adj[cur]){
                if(visited[nxt] == 1) continue;
                q.push(nxt);
            }
        }
    }
}

void dfs_recursion(){
    
}

void dfs(){

}

int main(){

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


}