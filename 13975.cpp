#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  while(t--){
    priority_queue<int, vector<int>, greater<>> pq;
    int k;

    while(k--){
      int temp;
      pq.push(temp);
      int answer;
      while(!pq.empty()){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        answer = a+b;
        pq.push(a+b);
      }
      cout << answer <<'\n'l;
    }
  }
  return 0;
}
