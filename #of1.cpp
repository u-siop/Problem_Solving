#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int DFS(vector<pair<int, int>> g){
    int min = 0;
    int cycle = 0;
    int sum;
    bool vis[402]={ 0, };
    vector<pair<int, int>> pre;
    stack<pair<int, int>> st;

    if(cycle!= 0){
        for(int i=0; i<cycle; i++){
            if(cycle == 1){
                min = sum;
            }
            else{
                if(min > sum)
                    min = sum;
            }
        }
        return min;
    }
    else{ return -1; }
}

int main(){
    int num_testcase;
    int num_vertex;
    int num_edge;
    vector<pair<int, int>> student[402];                            // students' manito info
    vector<int> disc;                                               // discovering new node
    vector<int> low;                                                // basis node for the cycle
    bool vis[402]={ 0, };                                           
    vector<pair<int, int>> cycle_nodes;                             // saving for cycle_node's node and cost

    int min = 0;
    int cycle = 0;
    int cycle_cost = -1;
    int sum;

    int vertex, edge ,cost;
    
    cin >> num_testcase;
    for(int i = 0; i < num_testcase; i++){
        cin >> num_vertex >> num_edge;
        for(int j = 0; j < num_edge; j++){
            cin >> vertex >> edge >> cost;
            student[vertex].push_back({edge,cost});
        }
        
        
        for(int i = 0; i < vertex; i++){
            vector<pair<int, int>> pre;
            stack<pair<int, int>> st;

            st.push(student[i].front());
            int time = 1; 
            vis[st.top().X] = true;
            pre.push_back(student[i].front()); student[i].pop_back();
            disc[st.top().X] = low[st.top().X] = time++;

            while(!st.empty()){
                int cur_vertex = st.top().X;
                bool found_new_node = false;

                for(int j = 0; i<student[cur_vertex].size(); i++){
                    int neighbor = student[j].back().X;

                    if(){

                    }
                    else if()
                }

            }

            if(cycle!= 0){
                for(int i=0; i<cycle; i++){
                    if(cycle == 1){
                        min = sum;
                    }
                    else{
                        if(min > sum)
                            min = sum;
                    }
                }
            }
            else{ min = -1; }

        }

        cout<< "#" << i << min << endl;
        for(int k = 0; k<vertex; k++){
            student[k].clear();                             // reset size
            vector<pair<int ,int>>().swap(student[k]);      // reset capacity
        }
    }

    return 0;
}