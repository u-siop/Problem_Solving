#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  priority_queue<unsigned int> pq;
  int n;
  cin >> n;

  while(n--){
    unsigned int temp;
    cin >> temp;
    if(temp){
      pq.push(temp);
    }
    else{
      if(pq.empty()) cout <<"0\n";
      else{
        cout << pq.top() << '\n';
        pq.pop();
      }
    }

  }

  return 0;
}
