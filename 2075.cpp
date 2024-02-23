#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  priority_queue<int, vector<int>, greater<>> pq;
  int n;
  cin >> n;

  for(int i=0; i<n*n; i++){
    int temp;
    cin >> temp;
    pq.push(temp);

    if(n < (int)pq.size()) pq.pop();
  }
  
  cout << pq.top();


  return 0;
}
