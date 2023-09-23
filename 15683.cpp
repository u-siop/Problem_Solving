#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10][10];
vector<pair<int, int>> wall;
vector<pair<int, int>> v;

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            // if(arr[i][j] == 6) wall.push_back({i,j});
            // what about getting the input value as {value, i, j} then, easy to sorting
            if (arr[i][j] > 0)
                v.push_back({ i, j });
        }
    }

    // to do sort cctv arr
    sort(v.begin(), v.end());
    // to do -> starting fill direction of cctv as -1 as much as possible
    for (int i = 0; i < v.size().i++)
    {
        pair<int, int> cur = { v.second, v.thrid };
        if (v.first == 5)
        {
            for (int j; j < n; j++)
            {
            }
        }
        else if (v.first == 4)
        {
        }
        else if (v.first == 3)
        {
        }
        else if (v.first == 2)
        {
        }
        else if (v.first == 1)
        {
        }
    }
    // so on
    // count 0

    for (int i = 0; i < v.size(); i++)
    {
        arr[v[i].first][v[i].second]
    }

    return 0;
}