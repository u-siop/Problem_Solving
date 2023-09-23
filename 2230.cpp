#include <bits/stdc++.h>
using namespace std;

// time limit : 2sec
// memory limit : 128MB
// n<=100,000
// m <= 20억
// |a[i]| <= 10억

int arr[100005];
int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int en = 0;
    int mn = 0x7fffffff;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    for(int st = 0; st < n; st++){
        while(en<n && arr[en] - arr[st] < m) en++;
        if(en == n) break;
        mn = min(mn, arr[en] - arr[st]);
    }
    cout << min;
    return 0;
}