#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    int mn = 0x7fffffff;
    int en = 0;
    int arr[100005];
    cin >> n >> s;
    for(int i=0; i<n; i++) cin >> arr[i];
    int total = arr[0];

    for(int st= 0; st<n; st++){
        while(en < n && total < s){
            en++;
            if(en != n) total += arr[en];
        }
        if(en == n) break;
        mn = min(mn, en - st + 1);
        total -= arr[st];
    }
    if(mn == 0x7fffffff) mn = 0;
    
    cout << mn;
    return 0;
}