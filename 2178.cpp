#include<bits/stdc++.h>
using namespace std;
#define MAX 102
#define X first
#define Y second

string board[MAX] = { 0, };     // 입력 최대 값이 100인데 왜 MAX를 102로 잡았을까?
int dist[MAX][MAX];             // -1 로 바로 초기화 못하나?
stack<pair<int, int>> St;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


void DFS(int N, int M){
    dist[0][0] = 0;
    St.push({0,0});

    while(!St.empty()){
        pair<int, int> cur = St.top(); St.pop();
        for(int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(dx < 0 || nx >= N || ny < 0 || ny >=M) continue;
            if(dist[nx][ny] >= 0  || board[nx][ny]!=1)  continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            St.push({nx,ny});

            // if(nx == N-1 && ny == M-1){
            //     if(min_d == 0){
            //         min_d = distance;
            //     }
            //     else{ min_d = min(min_d, distance); }
            // }
        }
    }
}

int main(){
    int N,M;
    int min_d;

    cin>>N>>M;
    // for(int i=0; i<N; i++){
    //     getline(cin, board[i], '/n');
    // }
    for(int i = 0; i<N; i++){
            cin>>board[i];
        }
    }
    min_d = DFS(N,M);
    
    cout<<min<<endl;
    return 0;
}