#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 12; i++){
        for(int j = 0; j <4; j++){
            cin >> board[i][j];
            if(board[i][j] == 'R'){
                R.push({i,j});
            }else if((board[i][j] == 'G'){
                G.push({i,j});
            }else if((board[i][j] == 'B'){
                B.push({i,j});
            }else if((board[i][j] == 'P'){
                P.push({i,j});
            }else if((board[i][j] == 'Y'){
                Y.push({i,j});
            }

            
        }
    }

    return 0;
}
