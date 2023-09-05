#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10][10];
vector<pair<int, int>> wall;
vector<tuple<int, int, int>> v;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            // if(arr[i][j] == 6) wall.push_back({i,j});
            if(arr[i][j]>0) v.push_back({arr[i][j], i,j});
        }
    }

    // to do sort cctv arr
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
        }
    }
    // so on
    // count 0




    return 0;
}