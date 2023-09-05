#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int board[42][42];
int sticker[102][12][12];


void orthogonal(){
    int temp[12][12];
    
}

int main(){
    cin >> n >> m >> k;
    int r,c;
    for(int i=0; i<k; i++){
        cin >> r >> c;
        for(int j=0; j<r; j++){
            for(int l=0; l<c; l++){
                cin >> sticker[i][j][l];
            }
        }
    }



    return 0;
}