<<<<<<< HEAD
#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int n, m, v;
list<int> l[1005];
bool visited[1005][1005];
stack<pair<int, int>> s;
queue<pair<int, int>> q;

void dfs()
{
    q.push({ 0, 1 });
    while (!q.empty())
    {
    }
}

void bfs()
{
}

int main()
{
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        l[a].push_back(b);
    }
    // sort()

    dfs();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = 0;
        }
    }
=======
#include <bits/stdc++.h>
using namespace std;

queue<int> q;
stack<int> s;
vector<int> adj[1005];
bool visited[1005];
int n, m, st;


void dfs(){
    s.push(st);
    while(!s.empty()){
        int cur = s.top(); s.pop();
        if(visited[cur]) continue;
        visited[cur] = 1;
        cout << cur << ' ';
        for(int i=0; i<adj[cur].size(); i++){
            int nxt = adj[cur][adj[cur].size()-1-i];
            if(visited[nxt]==1) continue;
            s.push(nxt);
        }
    }
}

void dfs_1(int cur){
    visited[cur] = 1;
    cout << cur << ' ';
    for(auto nxt : adj[cur]){
        if(visited[nxt]) continue;
        dfs_1(nxt);
    }
}

void bfs(){
    q.push(st);
    visited[st] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for(int i=0; i<adj[cur].size(); i++){
            int nxt = adj[cur][i];
            if(visited[nxt]) continue;
            q.push(nxt);
            visited[nxt] = 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> st;
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<=n; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    dfs();
    cout << '\n';
    fill(visited+1, visited+1+n, false);
>>>>>>> 2014891282f9c1f7b3c5d396f926300d05f01e00
    bfs();

    return 0;
}