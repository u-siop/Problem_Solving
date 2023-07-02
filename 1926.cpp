#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int m, n; // board[m][n]
bool board[500][500] = {
    0,
};
bool vis[500][500] = {
    0,
};
queue<pair<int, int>> Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int BFS(pair<int, int> cur)
{
    int area = 0;
    vis[cur.X][cur.Y] = 1;
    Q.push({ cur.X, cur.Y });

    while (!Q.empty())
    {
        cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if (vis[nx][ny] || board[nx][ny] != 1)
                continue;
            vis[nx][ny] = 1;
            Q.push({ nx, ny });
        }
        area++;
    }
    return area;
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    int num_area = 0;
    int temp;
    int max = 0;

    pair<int, int> cur;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                if (!vis[i][j])
                {
                    cur.X = i, cur.Y = j;
                    temp = BFS(cur);
                    num_area++;
                    if (temp > max)
                    {
                        max = temp;
                    }
                }
            }
        }
    }

    cout << num_area << endl;
    cout << max;

    return 0;
}