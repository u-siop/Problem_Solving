#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int arr[102];
bool isused[102];

void func(int k){
  if(k==m){
    for(int i=0; i<m; i++){
      cout << arr[i] <<' ';
    }
    cout << '\n';
  }
  for(int i=1; i<=n; i++){
    if(!isused[i]){
      arr[k] = i;
      isused[k] = true; 
      func(k+1);
      isused[k] = false;
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  func(0);
}
