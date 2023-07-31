#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int t, m, n, k;             // T : # of test case, m : length, n : width, k : # of cabbage
int board[52][52];
bool visited[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
stack<pair<int,int>> S;

void dfs(pair<int, int> p){
    visited[p.first][p.second] = 1;
    S.push({p.first,p.second});

    while(!S.empty()){
        pair<int, int> cur = S.top(); S.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx<0 || ny<0 || nx>=m || ny>= n) continue;
            if(board[nx][ny] != 1 || visited[nx][ny] == 1) continue;

            visited[nx][ny] = 1;
            S.push({nx,ny});
        }
    }
}

int main(){
    cin >> t;
    vector<pair<int, int>> v;
    int count[t] = {0, };

    for(int i=0; i<t; i++){
        cin >> m >> n >> k;
        int tmp1,tmp2;

        for(int j=0; j<k; j++){
            cin >> tmp1 >> tmp2;
            board[tmp1][tmp2] = 1;
            v.push_back({tmp1, tmp2});
        }
        
        for(int j=0; j<k; j++){
            if(!visited[v[j].first][v[j].second]){
                dfs({v[j].first, v[j].second});
                count[i]++;
            }
        }

        for(int j=0; j<52; j++){
            fill(board[j], board[j]+m, 0);
            fill(visited[j], visited[j]+m, 0);
        }
    }

    for(int i=0; i<t; i++){
        cout << count[i] << endl;
    }

    return 0;
}