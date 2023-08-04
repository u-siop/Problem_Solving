#include <bits/stdc++.h>
using namespace std;

// time limit : 1sec
// memory limit : 256MB
// 1<= N <= 10
// MAX K : 10^9

int main(){
    int n,k;
    int a[12];
    int count = 0;

    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=n-1; i>=0; i--){
        if(k/a[i] > 0){
            count += k/a[i];
            k = k % a[i];
        }
        if(k == 0) break;
    }

    cout << count << endl;
    return 0;
}