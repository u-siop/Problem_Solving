#include<bits/stdc++.h>
using namespace std;

class Graph {
    int numNodes;
    vector<vector<pair<int, int>>> adjList;
    vector<int> low;
    vector<int> disc;
    vector<bool> inStack;
    vector<int> cycleNodes;
    vector<vector<int>> cycles;
    vector<int> cycleCosts;
    stack<int> nodeStack;
    int minCost = -1;

public:
    Graph(int n) : numNodes(n), adjList(n), low(n), disc(n), inStack(n, false), cycleCosts(n) {}
    ~Graph(){
        vector<vector<pair<int, int>>>().swap(adjList);
        vector<int>().swap(low);
        vector<int>().swap(disc);
        vector<bool>().swap(inStack);
        vector<int>().swap(cycleNodes);
        vector<vector<int>>().swap(cycles);
        vector<int>().swap(cycleCosts);
    }

    void addEdge(int u, int v, int cost) {
        adjList[u].push_back({ v, cost });              // start from 'u' node to 'v' node and cost
    }

    void findCycleCosts() {
        for (int i = 0; i < numNodes; ++i) {
            if (disc[i] == 0) {                         // automatically set 0 each of values when initializing vector
                tarjan(i);                              // what does it mean disc[i]!= 0 ?
            }                                           // -> i : startNode, there's possible that some of nodes dont connected to another cycle
        }                                               // -> so that, for the new startNode

        // Print the cycles and their minimum costs
        // for (size_t i = 0; i < cycles.size(); ++i) {
        //     cout << "Cycle: ";
        //     for (int node : cycles[i]) {
        //         cout << node << " ";
        //     }
        //     cout << " | Minimum Cost: " << cycleCosts[i] << endl;
        // }

    }
    int getMinCost(){
        return minCost;
    }


private:
    void tarjan(int startNode) {                        // for new graph disconnected from others
        int time = 1;
        nodeStack.push(startNode);
        inStack[startNode] = true;                                      // similar to vis[]  checking vistied or not
        disc[startNode] = low[startNode] = time++;                      // -> nope, when a cycle is detected, this mark make it possible to traverse to behind
        cycleNodes.push_back(startNode);

        while (!nodeStack.empty()) {                                    // DFS for the whole nodes and edges
            int currentNode = nodeStack.top();

            bool foundUnvisitedNeighbor = false;                        // this for loop means starting each of currend node's DFS
            for (const auto& neighbor : adjList[currentNode]) {         // auto : considering variable's type itself by initializing, like following adjList[]
                int neighborNode = neighbor.first;                      // so that neighbor : pair<int, int> -> {node, cost}
                                                                        // const is making the variable number
                if (disc[neighborNode] == 0) {
                    nodeStack.push(neighborNode);
                    inStack[neighborNode] = true;
                    disc[neighborNode] = low[neighborNode] = time++;                // dont be confused from neighborNode and currentNode
                    cycleNodes.push_back(neighborNode);
                    foundUnvisitedNeighbor = true;                                  // this is a flag for not going to condition for cycle
                    break;
                }
                else if (inStack[neighborNode]) {                                   // found the node but already visited and also if it is in the stack
                    low[currentNode] = min(low[currentNode], disc[neighborNode]);  // one more checking that this curret node is really from basis node
                }
            }

            if (!foundUnvisitedNeighbor) {                                          // after some of drawing edges, if there's no more new node 
                if (low[currentNode] == disc[currentNode]) {                        // and if DFS found a cycle so that try to calculate total cost of this cycle
                    vector<int> cycle;
                    int topNode;                                                    // go back following back edge and back edge from topNode
                    int sumCosts = 0;
                    // int minCost = numeric_limits<int>::max();                    // numeric_limits<int>::max() -> max value of <int> so it means 2147483647
                    do {
                        topNode = cycleNodes.back();                                // cycleNodes provide back edge
                        cycleNodes.pop_back();
                        inStack[topNode] = false;                                   // reset init
                        cycle.push_back(topNode);
                        // minCost = min(minCost, cycleCosts[topNode]);
                        sumCosts += cycleCosts[topNode];
                    } while (topNode != currentNode);

                    if(!cycles.empty()){
                        minCost = sumCosts;
                    }
                    else{
                        minCost = min(minCost, sumCosts);
                    }
                    cycles.push_back(cycle);
                    // cycleCosts.push_back(minCost);
                }

                nodeStack.pop();                                                    // there's no more new node and cannot find cycle from this node, then just pop()
            }
        }
    }


};

int main() {
    // int numNodes, numEdges;
    // cout << "Enter the number of nodes: ";
    // cin >> numNodes;
    // cout << "Enter the number of edges: ";
    // cin >> numEdges;

    // Graph graph(numNodes);

    // cout << "Enter the edges (start, end, cost):\n";
    // for (int i = 0; i < numEdges; ++i) {
    //     int u, v, cost;
    //     cin >> u >> v >> cost;
    //     graph.addEdge(u, v, cost);
    // }

    // graph.findCycleCosts();

    // return 0;
    int numTestcase;
    int numNodes, numEdges;
    int minCost;
    cin >> numTestcase;

    for(int i = 1; i <= numTestcase; ++i){
        cin >> numNodes >> numEdges;
    
        Graph graph(numNodes);

        for(int i = 0; i < numEdges; ++i){
            int u, v, cost;
            cin >> u >> v >> cost;
            graph.addEdge(u, v, cost);
        }

        graph.findCycleCosts();
        minCost = graph.getMinCost();
        
        cout<< "#" << i << " " << minCost << endl;
    }

    return 0;
}
