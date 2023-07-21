#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// int bfs(){
//     int dx[4] = {1, 0, -1, 0};
//     int dy[4] = {0, 1, 0, -1};
//     visited[0][0] = 1;
//     Q.push({0,0});

//     while(!Q.empty()){
//         pair<int, int> cur = Q.front(); Q.pop();
//         for(int i=0; i<4; i++){
//             int nx = cur.X + dx[i];
//             int ny = cur.Y + dy[i];

//             if(nx < 0 || ny < 0 || nx >= m || ny >= n ) continue;
//             if(visited[nx][ny] == 1 || board[nx][ny] != 0) continue;
//             visited[nx][ny] = 1;
//             Q.push({nx,ny});
//         }
//     }
// }

int main() {
    int m, n;
    int temp;
    int day = -1;
    cin >> m >> n;                      // m : row , n : col
    queue<pair<int, int>> Q;
    vector<vector<int>> board(n, vector<int>(m, 0));
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            if (temp >= 1) {
                Q.push({ i,j });
            }
            board[i][j] = temp;
        }
    }


    while (!Q.empty()) {
        int size = Q.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> cur = Q.front(); Q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (board[nx][ny] != 0) continue;
                board[nx][ny] = 1;
                Q.push({ nx,ny });
            }
        }
        day++;
    }

    for (int i = 0; i < n; i++) {
        if (find(board[i].begin(), board[i].end(), 0) != board[i].end()) {         // vector 내에 0이 존재함?
            day = -1;
            break;
        }
    }

    cout << day << endl;

    return 0;
}