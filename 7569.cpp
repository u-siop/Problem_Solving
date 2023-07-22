#include <bits/stdc++.h>
using namespace std;

// int board[102][102][102];               // 초기화 하지 않은 int 배열은 0으로 채워짐
int dist[102][102][102];

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};
queue<tuple<int, int, int>> Q;          // get<0>(Q.top()), get<1>(Q.top()), get<2>(Q.top())

int main(){
    int m,n,h;
    cin >> m >> n >> h;    // m : row, n : col, h : height
    vector<vector<vector<int>>> board(h, vector<vector<int>>(n, vector<int>(m,0)));
    for(int i = 0; i<h; i++){
        for(int j = 0; i<n; j++){
            for(int k = 0; k<m; k++){
                cin >> board[i][j][k];
                if(board[i][j][k] == 1){
                    dist[i][j][k] = 1;
                    Q.push({i,j,k});
                }
            }
        }
    }

    while(!Q.empty()){
        tuple<int, int, int> cur = Q.front(); Q.pop();
        for(int i=0; i<6; i++){
            int nx = get<2>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];
            int nz = get<0>(cur) + dz[i];
            
            if(nx<0 || ny<0 || nz<0 || nx>= m || ny>=n || nz>=h) continue;
            if(board[nz][ny][nx]!=1 || dist[nz][ny][nx] >= 0) continue;
            board[nz][ny][nx] = 1;
            dist[nz][ny][nx] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            Q.push({nz,ny,nx});
        }
    }

    int ans = 0;
    for(int i = 0; i<h; i++){
        for(int j=0; j<n; j++){
            if(find(board[i][j].begin(), board[i][j].end(), 0) != board[i][j].end()){
                ans = -1;
                break;
            }
            else{
                for(int k = 0; k<m; k++){
                ans = max(ans,dist[i][j][k]);
                }
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}