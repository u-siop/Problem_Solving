#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10][10];
vector<pair<int, int>> wall;
vector<pair<int, int>> v;


int main(){

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            // if(arr[i][j] == 6) wall.push_back({i,j});
            if(arr[i][j]>0) v.push_back({i,j});
        }
    }

    // to do sort cctv arr
    // to do -> starting fill direction of cctv as -1 as much as possible
    // so on
    // count 0

    for(int i=0; i<v.size(); i++){
        arr[v[i].first][v[i].second] 
    }


    return 0;
}