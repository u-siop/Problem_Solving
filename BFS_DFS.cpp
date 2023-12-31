#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MAX 100

int board[MAX][MAX] ={ 0, };
bool vis[MAX][MAX] = { 0, };
int dx[4] = {1,0,-1,0};             // x : row
int dy[4] = { 0,1,0,-1};            // y : column

void BFS(){
    queue<pair<int, int>> Q;

    Q.push({0,0});
    vis[0][0] = 1;

    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >=MAX < 0 || ny <0 || ny >=MAX ) continue;
            if( vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
}

void DFS(){
    stack<pair<int, int>> St;
    
    vis[0][0] = 1;
    St.push({0,0});

    while(!St.empty()){
        pair<int, int> cur = St.top(); St.pop();
        for(int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;

            vis[nx][ny] = 1;
            St.push({nx,ny});
        }
    }
}