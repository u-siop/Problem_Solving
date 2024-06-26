#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ret;
int rec[10][10];
int vis[10][10];
vector<pair<int, int>> wall, vir;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(vis[ny][nx]) continue;
        if(rec[ny][nx] == 1) continue;
        vis[ny][nx] = 1;
        dfs(ny, nx);
    }
}

int go(){
    memset(vis, 0, sizeof(vis));
    for(pair<int, int> a: vir){
        vis[a.first][a.second] = 1;
        dfs(a.first, a.second);
    }

    int cnt = 0;

    for(int i=0; i<n; i++){
        for(int j=0; i<m; j++){
            if(rec[i][j] == 0 && vis[i][j] == 0) cnt++;
        }
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> rec[i][j];
            if(rec[i][j] == 0){
                wall.push_back({i,j});
            }
            if(rec[i][j] == 2){
                vir.push_back({i,j});
            }
        }
    }

    int l = wall.size();
    for(int i = 0; i < l; i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                rec[wall[i].first][wall[i].second] = 1;
                rec[wall[j].first][wall[j].second] = 1;
                rec[wall[k].first][wall[k].second] = 1;
                ret = max(ret, go());

                rec[wall[i].first][wall[i].second] = 0;
                rec[wall[j].first][wall[j].second] = 0;
                rec[wall[k].first][wall[k].second] = 0;
            }
        }
    }

    cout << ret << '\n';
    return 0;
}



// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// #include <stack>
// #include <cmath>
// #include <string.h>

// using namespace std;

// int a[10][10];
// int b[10][10];
// int visited[10][10];
// int n, m;
// int ret;

// vector<pair<int, int>> vecBlank;

// int dy[] = { -1, 0, 1, 0 };
// int dx[] = { 0, 1, 0, -1 };

// void DFS(int y, int x)
// {
// 	visited[y][x] = 1;
// 	b[y][x] = 2;

// 	for (int i = 0; i < 4; ++i)
// 	{
// 		int ny = y + dy[i];
// 		int nx = x + dx[i];

// 		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
// 		if (b[ny][nx] != 0) continue;

// 		DFS(ny, nx);
// 	}
// }

// int GetSafeCnt()
// {
// 	int cnt = 0;

// 	for (int y = 0; y < n; ++y) {
// 		for (int x = 0; x < m; ++x) {
// 			if (b[y][x] == 0) ++cnt;
// 		}
// 	}

// 	return cnt;
// }

// int main()
// {
// 	cin >> n >> m;

// 	for (int i = 0; i < n; ++i) {
// 		for (int j = 0; j < m; ++j) {
// 			cin >> a[i][j];

// 			if (a[i][j] == 0)
// 				vecBlank.push_back({i, j});
// 		}
// 	}

// 	for (int i = 0; i < vecBlank.size(); ++i) {
// 		for (int j = i + 1; j < vecBlank.size(); ++j) {
// 			for (int k = j + 1; k < vecBlank.size(); ++k) {
// 				//cout << i << ", " << j << ", " << k << "\n";

// 				// 초기화
// 				memcpy(b, a, sizeof(a));
// 				memset(visited, 0, sizeof(visited));
				
// 				// 벽 3개 설치
// 				b[vecBlank[i].first][vecBlank[i].second] = 1;
// 				b[vecBlank[j].first][vecBlank[j].second] = 1;
// 				b[vecBlank[k].first][vecBlank[k].second] = 1;

// 				// DFS 로 바이러스 확산
// 				for (int y = 0; y < n; ++y) {
// 					for (int x = 0; x < m; ++x) {
// 						if (b[y][x] != 2 || visited[y][x]) continue;

// 						DFS(y, x);
// 					}
// 				}

// 				// 안전영역 확인
// 				int safeCnt = GetSafeCnt();
// 				ret = max(ret, safeCnt);
// 			}
// 		}
// 	}

// 	cout << ret << "\n";
		
// 	return 0;
// }
