#include <bits/stdc++.h>
using namespace std;

// time limit : 1sec
// memory limit : 256MB
// N <= 100,000
// M <= 100,000
int f[100005];
int d[100005];

// int main(){
//     int n,m,a,b;
//     cin >> n >> m;
//     for(int i=0; i<n; i++){
//         cin >> d[i];
//     }

//     for(int i=0; i<m; i++){
//         int sum = 0;
//         cin >> a >> b;
//         for(int j=a-1; j<b; j++){
//             sum += d[j];
//         }
//         cout << sum << endl;
//     }

//     return 0;
// }
// -> O(NM) -> boom

// -> at this time, using a[i], d[i] = a[0] + a[1] + ... + a[i]
//                              => a[i] + a[i+1] + ... a[j] = d[j] - d[i-1];
int main(){
    int n,m,a,b;
    cin >> n >> m;
    d[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> f[i];
        d[i] = d[i-1] + f[i];
    }

    for(int i=0; i<m; i++){
        cin >> a >> b;
        cout << d[b] - d[a-1] << endl;
    }
}