#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <limits>
using namespace std;

class Graph {
    int numNodes;
    vector<vector<pair<int, int>>> adjList;
    vector<int> low;
    vector<int> disc;
    vector<bool> inStack;
    vector<int> cycleNodes;
    vector<int> cycleCosts;
    vector<vector<int>> cycles;
    stack<int> nodeStack;
    int minCost = numeric_limits<int>::max();

public:
    Graph(int n) : numNodes(n), adjList(n + 1), low(n + 1), disc(n + 1), inStack(n + 1, false) {}

    void addEdge(int u, int v, int cost) {
        adjList[u].push_back({ v, cost });
    }

    void findCycleCosts() {
        for (int i = 1; i <= numNodes; i++) {
            if (disc[i] == 0) {
                tarjan(i);
                cycleNodes.clear();
                cycleCosts.clear();
            }
        }
    }

    void setMinCost(int cost) {
        minCost = cost;
    }

    int getMinCost() {
        return minCost;
    }

    void clearData() {
        low.clear();
        disc.clear();
        inStack.clear();
        cycles.clear();
        minCost = numeric_limits<int>::max();
        while (!nodeStack.empty()) {
            nodeStack.pop();
        }
    }

private:
    void tarjan(int startNode) {
        int time = 1;
        nodeStack.push(startNode);
        inStack[startNode] = true;
        disc[startNode] = low[startNode] = time++;
        cycleNodes.push_back(startNode);

        while (!nodeStack.empty() && nodeStack.top() <= numNodes) {
            int currentNode = nodeStack.top();
            bool foundUnvisitedNeighbor = false;

            for (const auto& neighbor : adjList[currentNode]) {
                int neighborNode = neighbor.first;
                int neighborCost = neighbor.second;

                if (disc[neighborNode] == 0) {
                    nodeStack.push(neighborNode);
                    inStack[neighborNode] = true;
                    disc[neighborNode] = low[neighborNode] = time++;
                    cycleNodes.push_back(neighborNode);
                    cycleCosts.push_back(neighborCost);
                    foundUnvisitedNeighbor = true;
                    break;
                }
                else if (inStack[neighborNode]) {
                    low[currentNode] = min(low[currentNode], disc[neighborNode]);
                }
            }

            if (!foundUnvisitedNeighbor) {
                if (low[currentNode] == disc[currentNode] && currentNode != startNode) {
                    vector<int> cycle;
                    int topNode;
                    int sumCosts = 0;
                    do {
                        topNode = cycleNodes.back();
                        sumCosts += cycleCosts.back();
                        cycleNodes.pop_back();
                        cycleCosts.pop_back();
                        inStack[topNode] = false;
                        cycle.push_back(topNode);
                    } while (topNode != currentNode);

                    minCost = min(minCost, sumCosts);

                    cycles.push_back(cycle);
                }

                nodeStack.pop();
            }
        }
    }
};

int main() {
    int numTestcases;
    cin >> numTestcases;

    for (int i = 1; i <= numTestcases; ++i) {
        int numNodes, numEdges;
        cin >> numNodes >> numEdges;

        Graph graph(numNodes);

        for (int i = 0; i < numEdges; ++i) {
            int u, v, cost;
            cin >> u >> v >> cost;
            if (u == v) {
                graph.setMinCost(cost);
            }
            graph.addEdge(u, v, cost);
        }

        graph.findCycleCosts();
        int minCost = graph.getMinCost();

        graph.clearData();

        cout << "#" << i << " " << minCost << endl;
    }

    return 0;
}
