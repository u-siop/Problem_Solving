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
    bfs();

    return 0;
}