// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int n, mx = 0;
// int cnt = 0, mxcnt = 0;
// long long mxval = -(1ll << 62) - 1;
// int arr[1000002];

// int main()
// {
//     cin >> n;
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }

//     sort(arr, arr+n);

//     for(int i=0; i<n; i++){
//         for(int j=i; ; j++){
//             if(arr[i] == arr[j]){
//                 cnt++;
//             }
//             else{
//                 if(mxcnt < cnt){
//                     mxcnt = cnt + 1;
//                     mxval = i;
//                     cnt = 0;
//                 }
                
//                 i=j;
//                 break;
//             }
//         }
//     }
// }


#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
  int cnt = 0;
  long long mxval = -(1ll << 62) - 1; // 1을 long long으로 형변환하지 않고 1 << 62로 작성시 int overflow 발생
  int mxcnt = 0;
  for(int i = 0; i < n; i++){
    if(i == 0 || a[i-1] == a[i]) cnt++; // i가 0인 경우 앞쪽 식이 true이기 때문에 a[i-1]을 참조하지 않음
    else{
      if(cnt > mxcnt){
        mxcnt = cnt;
        mxval = a[i-1];
      }
      cnt = 1;
    }
  }
  if(cnt > mxcnt) mxval = a[n-1]; // 제일 마지막 수가 몇 번 등장했는지를 별도로 확인
  cout << mxval;
}