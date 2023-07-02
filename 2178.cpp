#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool board[100][100] = {
    0,
};
bool vis[100][100] = {
    0,
};
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, 1 };

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    queue<pair<int, int>> Q;
}