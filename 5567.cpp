#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, ans = 0;
int num = 0;

vector<int> adj[505];
vector<int> cnt[505];
queue<int> Q;

void bfs(){
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        int l = adj[cur].size();
        for(int i = 0; i < l; i++){
            Q.push(adj[cur][i]);
            cnt[cur].push_back(num);
        }
    }
    num++;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    Q.push(1);

    // bfs로 상근으로부터 친구 거리 재기
    bfs();
    // 거리 2이하인 사람 count

    cout << ans << "\n";
}