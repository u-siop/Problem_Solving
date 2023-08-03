#include <bits/stdc++.h>
using namespace std;

int n;
int board[100002][100002];
bool visited[100002][100002];
int temp = 0;
stack<pair<int, int>> S;
string anw;

void dfs(){
    for(int i=1; i<n-1; i++){
        visited[0][i] = 1;
        S.push({0,i});

        while(!S.empty()){
            pair<int, int> cur = S.top(); S.pop();
            anw += cur.second;
            for(int j=0; j<n; j++){
                visited[j][cur.second] = 1;
                visited[cur.first][j] = 1;
            }
            
            for(int j=0; j<n; j++){
                if(cur.first == 6 && visited[cur.first + 1][j] == 0){
                    anw+=j;
                    break;
                }
                if(visited[cur.first + 1][j] == 0){
                    visited[cur.first + 1][j] = 1;
                    S.push({cur.first + 1,j});
                }
                else temp++;
            }
            if(temp == 8){
                anw.pop_back();
                continue;
            }
        }
        // todo
        // fill every components visited[][] == 0;
        for(int j=0; j<n; j++){
            fill(visited[j],visited[j]+n,0);
        }
    }
}

int main(){
    cin >> n;
    dfs();

    for(int i=0; i<n; i++){
        cout << anw[i] << endl;
    }

    return 0;
}