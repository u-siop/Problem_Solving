#include <bits/stdc++.h>
using namespace std;

// time limit : 2sec
// memory limit : 128MB
// N <= 100,000

priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    int n;
    int anw = 0;            // think about the maximum anw so careful when i declare variable, it need a int or long long whatever
    cin >> n;
    for(int i=0; i<n; i++){
        int bound;
        cin >> bound;
        pq.push(bound);
    }
    // while(!pq.empty()){
    //     if(sum == 0){
    //         sum += pq.top(); pq.pop();
    //         sum += pq.top(); pq.pop();
    //     }
    //     else{
    //         sum += sum;
    //         sum += pq.top(); pq.pop();
    //     }
    // }

    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        anw += a + b;
        pq.push(a+b);
    }

    cout << anw << endl;

    return 0;
}