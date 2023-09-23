#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    vector<int> tp_sort[7];
    vector<int> result;
    int indegree[7];
    int n = 7;

    tp_sort[0].push_back(1);
    tp_sort[2].push_back(1);
    tp_sort[2].push_back(3);
    tp_sort[3].push_back(1);
    tp_sort[3].push_back(4);
    tp_sort[4].push_back(5);
    tp_sort[6].push_back(4);

    for(int i=0; i<7; i++){
        for(int j=0; j<tp_sort[i].size(); j++){
            indegree[tp_sort[i][j]]++;
        }
    }

    // for(int i=0; i<7; i++){
    //     if(indegree[i] == 0){
    //         q.push(indegree[i]);
    //     }
    //     else{
    //         for(int j=0; j<tp_sort[i].size(); j++){
    //             indegree[tp_sort[i][j]]--;
    //         }
    //     }
    // }

    for(int i=0; i<7; i++){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front(); q.pop();
        result.push_back(cur);

        for(int nxt: tp_sort[cur]){
            indegree[nxt]--;
            if(indegree[nxt] == 0) q.push(nxt);
        }
    }

    if(result.size() != n) cout << "cycle exists\n";
    else{
        for(int i=0; i<result.size(); i++){
            cout << result[i] << " ";
        }
    }
}