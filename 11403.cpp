#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i< n; i++){
        for(int j =0; j<n; j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                q.push({i,j});
            }
        }
    }

    return 0;
}
