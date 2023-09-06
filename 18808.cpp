#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int r, c;
int board[42][42];
int sticker[12][12];

void rotate(){
    int temp[12][12];
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            temp[i][j] = sticker[i][j];
    
    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++){
            sticker[i][j] = temp[r-1-j][i];
        }
    }

    swap(r, c);
}

bool patchable(int x, int y){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(board[x+i][y+j] == 1 && sticker[i][j] == 1)
                return false;
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(sticker[i][j] == 1)
                board[x+i][y+j] = 1;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++){
        cin >> r >> c;
        for (int j = 0; j < r; j++){
            for (int l = 0; l < c; l++){
                cin >> sticker[j][l];
            }

        }
        for(int rot = 0; rot<4; rot++){
            bool is_paste = false;
            for(int x = 0; x<=n-r; x++){
                if(is_paste) break;
                for(int y=0; y<= m-c; y++){
                    if(patchable(x,y)){
                        is_paste = true;
                        break;
                    }
                }
            }

            if(is_paste) break;
            rotate();
        }
    }
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            count += board[i][j];
        }
    }
    cout << count <<'\n';

    return 0;
}