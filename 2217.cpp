#include <bits/stdc++.h>
using namespace std;

// time limit : 2sec
// memory limit : 192MB
// 1<= N <= 100,000

int v[100005];
int main(){
    int n;
    cin >> n;
    int anw = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(v,v+n);
    // if(v[n-1] >= v[0] * (n-1)) anw = v[n-1];
    // else anw = v[0]*n;

    // cout << anw << endl;

    // return 0;
    for(int i=1; i<=n; i++){
        anw = max(anw, i*v[n-i]);
    }

    cout << anw << endl;
    
    return 0;
}