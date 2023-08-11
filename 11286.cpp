#include <bits/stdc++.h>
using namespace std;

// time limit : 1sec
// memory limit : 256MB

class cmp{
public:
    bool operator() (int a, int b){
        if(abs(a) != abs(b)) return abs(a) > abs(b);
        return a>0 && b<0;
    }
};

priority_queue<int, vector<int>, cmp> pq;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x == 0){
            if(pq.empty()) cout << "0\n";
            else{
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }
}