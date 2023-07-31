#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <algorithm>
using namespace std;

class Graph {
    int num_nodes;
    vector<vector<pair<int, int>>> adj_list;

public:
    Graph(int num) {
        num_nodes = num;
        adj_list.resize(num_nodes + 1);
    }

    void add_edge(int u, int v, int cost) {
        adj_list[u].push_back(make_pair(v, cost));
    }

    int tarjan() {
        stack<int> st;
        vector<bool> visited(num_nodes + 1, false);
        vector<bool> on_stack(num_nodes + 1, false);
        vector<int> low(num_nodes + 1, numeric_limits<int>::max());
        vector<int> ids(num_nodes + 1, numeric_limits<int>::max());
        int id_counter = 0;
        int cycle_cost = numeric_limits<int>::max();

        void dfs(int v) {
            st.push(v);
            on_stack[v] = true;
            visited[v] = true;
            low[v] = ids[v] = id_counter++;

            for (auto neighbor : adj_list[v]) {
                int neighbor_node = neighbor.first;
                int cost = neighbor.second;
                if (!visited[neighbor_node]) {
                    dfs(neighbor_node);
                }
                if (on_stack[neighbor_node]) {
                    low[v] = min(low[v], low[neighbor_node]);
                }
            }

            if (low[v] == ids[v]) {
                int cycle_min_cost = numeric_limits<int>::max();
                vector<int> cycle_nodes;
                while (true) {
                    int node = st.top();
                    st.pop();
                    on_stack[node] = false;
                    cycle_nodes.push_back(node);
                    cycle_min_cost = min(cycle_min_cost, low[node]);
                    if (node == v) {
                        break;
                    }
                }

                if (cycle_nodes.size() > 1) {
                    cycle_cost = min(cycle_cost, cycle_min_cost);
                }
            }
        }

        function<void(int)> dfs = [&](int v) {
            dfs(v);
        };


        for (int i = 1; i <= num_nodes; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        return (cycle_cost != numeric_limits<int>::max()) ? cycle_cost : -1;
    }
};

int main() {
    int test_cases;
    cin >> test_cases;

    for (int case_num = 1; case_num <= test_cases; case_num++) {
        int num_nodes, num_edges;
        cin >> num_nodes >> num_edges;
        Graph graph(num_nodes);

        for (int i = 0; i < num_edges; i++) {
            int u, v, cost;
            cin >> u >> v >> cost;
            graph.add_edge(u, v, cost);
        }

        int min_cost = graph.tarjan();
        cout << "#" << case_num << " " << min_cost << endl;
    }

    return 0;
}
