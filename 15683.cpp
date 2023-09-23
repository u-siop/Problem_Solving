#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10][10];
vector<pair<int, int>> wall;
vector<tuple<int, int, int>> v;


<<<<<<< HEAD
int main()
{
=======

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
>>>>>>> 2014891282f9c1f7b3c5d396f926300d05f01e00

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            // if(arr[i][j] == 6) wall.push_back({i,j});
<<<<<<< HEAD
            // what about getting the input value as {value, i, j} then, easy to sorting
            if (arr[i][j] > 0)
                v.push_back({ i, j });
=======
            if(arr[i][j]>0) v.push_back({arr[i][j], i,j});
>>>>>>> 2014891282f9c1f7b3c5d396f926300d05f01e00
        }
    }

    // to do sort cctv arr
<<<<<<< HEAD
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
=======
    sort(v.begin(), v.end(),greater<int>());

    // to do -> starting fill direction of cctv as -1 as much as possible
    for(int i=0; i<m; i++){
        pair<int, int> cur = {get<1>(v[i]), get<2>(v[i])};
        switch(get<0>(v[i])){
            case 5:
            for(int j=0; j<n; j++){

            }
            break;

            case 4:
            break;

            case 3:
            break;

            case 2:
            break;

            case 1:
            break;

            default:
            break;
>>>>>>> 2014891282f9c1f7b3c5d396f926300d05f01e00
        }
    }
    // so on
    // count 0

<<<<<<< HEAD
    for (int i = 0; i < v.size(); i++)
    {
        arr[v[i].first][v[i].second]
    }
=======

>>>>>>> 2014891282f9c1f7b3c5d396f926300d05f01e00

    return 0;
}