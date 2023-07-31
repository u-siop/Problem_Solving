//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <limits>

using namespace std;
typedef pair<int, int> pi;
struct Directed_Graph {
	int n;
	vector<vector<int>>edge;
	vector<vector<pi>>G;
	vector<int>discovered;
	vector<int>scc_id;
	stack<int>st;
	int scc = 0, counter = 1;
	Directed_Graph(int vertex) {
		n = vertex;
		G = vector<vector<pi>>(n + 1, vector<pi>(0));
		discovered = vector<int>(n + 1, 0);
		scc_id = vector<int>(n + 1, 0);
	}
	void Get_edge(int m, bool weighted) {
		for (int i = 1; i <= m; i++) {
			int a, b, w = 1;
			cin >> a >> b;
			if (weighted) cin >> w;
			edge.push_back({ a,b,w });
			G[a].push_back({ b,w });
		}
	}
	void Run_SCC() {
		for (int i = 1; i <= n; i++) if (!discovered[i]) DFS(i);
	}
	vector<vector<int>>Get_SCC() {
		Run_SCC();
		vector<vector<int>>ret = vector<vector<int>>(scc + 1);
		for (int i = 1; i <= n; i++) {
			ret[scc_id[i]].emplace_back(i);
		}
		return ret;
	}
	int DFS(int cur) {
		discovered[cur] = counter++;
		int ret = discovered[cur];
		st.push(cur);
		for (auto it : G[cur]) {
			int nxt = it.first;
			if (!discovered[nxt]) ret = min(ret, DFS(nxt));
			else if (!scc_id[nxt]) ret = min(ret, discovered[nxt]);
		}
		if (ret >= discovered[cur]) {
			++scc;
			while (st.top() != cur) {
				scc_id[st.top()] = scc;
				st.pop();
			}
			scc_id[st.top()] = scc;
			st.pop();
		}
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int num_testcase;
	cin >> num_testcase;
	for (int i = 1; i <= num_testcase; i++) {
		int n, m; cin >> n >> m;
		Directed_Graph DG(n);
		DG.Get_edge(m, true);

		vector<vector <int>> v = DG.Get_SCC();
		// sort(v.begin(), v.end());
		for (int i = 1; i < v.size(); i++) {
			for (int x : v[i]) {
				cout << x << " ";
				cout << -1 << endl;
			}
		}
		cout << "#" << i << " "<< num_testcase<< endl;
	}
}