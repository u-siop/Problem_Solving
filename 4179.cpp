#include <bits/stdc++.h>
using namespace std;

// time limit : 1sec
// memory limit : 256MB
// 1<= R,C <=1,000 (R:row, C : column)
#define MAX 1005
#define X first
#define Y second

bool board[MAX][MAX];
bool fire[MAX][MAX];
queue<pair<int, int>> q_f;
queue<pair<int, int>> q_j;
int dist[MAX][MAX];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    int r, c;
    char temp;
    int count = 0;
    bool flag = false;
    cin >> r >> c;
    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= r; j++) {
            cin >> temp;
            if (temp == '#') {
                board[i][j] = 1;
            }
            else if (temp == '.') {
                board[i][j] = 0;
            }
            else if (temp == 'J') {   // will be given only 1 J
                board[i][j] = 0;
                q_j.push({ i,j });
            }
            else {                   // temp == 'F', can be given more than 1 F
                fire[i][j] = 1;
                board[i][j] = 0;
                q_f.push({ i,j });
            }
        }
    }
    while (!q_f.empty()) {
        int size = q_f.size();
        while(size--) {
            pair<int, int> cur_f = q_f.front(); q_f.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur_f.X + dx[i];
                int ny = cur_f.Y + dy[i];

                if (nx < 1 || ny < 1 || nx >= c + 1 || ny >= r + 1) continue;
                if (board[nx][ny] == 1 || fire[nx][ny] == 1) continue;
                fire[nx][ny] = 1;
                q_f.push({ nx,ny });
            }
        }
        if (!q_j.empty()) {
            int size = q_j.size();
            while (size--) {
                pair<int, int> cur_j = q_j.front(); q_j.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = cur_j.X + dx[i];
                    int ny = cur_j.Y + dy[i];

                    if (board[nx][ny] == 1 || fire[nx][ny] == 1) continue;
                    if (nx < 0 || ny < 0 || nx >= c + 1 || ny >= r + 1) {
                        count = dist[cur_j.X][cur_j.Y] + 1;
                        flag = true;
                        break;
                    }
                    dist[nx][ny] = dist[cur_j.X][cur_j.Y] + 1;
                    q_j.push({ nx,ny });
                }
            }
        }
    }
    // to do
    // assign count value from dist


    if (flag == true) cout << count << endl;
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}