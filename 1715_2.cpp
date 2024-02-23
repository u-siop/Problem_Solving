#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  priority_queue<int, vector<int>, greater<int>> pq;
  int n;

  cin >> n;
  for(int i=0; i<n; i++){
    int x;
    c >> x;
    pq.push(x);
  }

  int answer;

  while(!pq.empty()){
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    answer = a + b;
    pq.push(a+b);
  }

  cout << answer;

  return 0;
}
