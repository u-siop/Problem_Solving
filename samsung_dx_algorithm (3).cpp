#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <limits>
using namespace std;

int num[10101];
int low[10101];
bool visit[10101];
int cnt = 0;
vector<int> g[10101];
stack<int> s;
vector< vector<int> > ans;

void dfs(int now) {
	visit[now] = 1;
	s.push(now);
	num[now] = ++cnt;
	low[now] = cnt;

	for (auto nxt : g[now]) {
		if (!num[nxt]) {
			dfs(nxt);
			low[now] = min(low[now], low[nxt]);
		}
		else if (visit[nxt]) {
			low[now] = min(low[now], num[nxt]);
		}
	}

	if (low[now] == num[now]) {
		vector<int> scc;
		while (!s.empty()) {
			int poped = s.top(); s.pop();
			scc.push_back(poped);
			visit[poped] = 0;
			if (now == poped) break;
		}
		sort(scc.begin(), scc.end());
		ans.push_back(scc);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int num_testcase;
	cin >> num_testcase;
	for (int i = 1; i<=num_testcase; i++) {
		int n, m; cin >> n >> m;
		while (m--) {
			int a, b; cin >> a >> b;
			g[a].push_back(b);
		}

		for (int i = 1; i <= n; i++) {
			if (!num[i]) dfs(i);
		}
		cout << ans.size() << "\n";

		sort(ans.begin(), ans.end());
		for (auto v : ans) {
			for (auto i : v) cout << i << " ";
			cout << "-1\n";
		}
	}
}