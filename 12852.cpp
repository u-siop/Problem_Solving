#include <bits/stdc++.h>
using namespace std;

// time limit : 0.5sec
// memory limit : 512 MB
// N <= 100,000
int d[1000005];
int before[1000005];

int main(){
    int n;
    cin >> n;

    d[1] = 0;
    before[1] = 1;

    for(int i=2; i<=n; i++){
        d[i] = d[i-1]+1;
        before[i] = i-1;
        if(i%2 == 0){
            if(d[i] > d[i/2] + 1 ){
                d[i] = min(d[i], d[i/2]) + 1;
                before[i] = i/2;
            }
        }
        if(i%3 == 0){
            if(d[i] > d[i/3] +1){
                d[i] = min(d[i], d[i/3]) + 1;
                before[i] = i/3;
            }
        }
    }

    cout << d[n] << endl;
    // while(1){
    //     cout << n << " ";
    //     if(n==1) break;
    //     if(d[n] == d[n-1] +1 ){
    //         n = n - 1;
    //     }
    //     else if(n%2 == 0 && d[n] == d[n/2] +1){
    //         n = n/2;
    //     }
    //     else if(n%3 == 0 && d[n] == d[n/3] + 1){
    //         n = n/3;
    //     }
    // }
    while(1){
        cout<<n<<" ";
        if(n == 1) break;
        n = before[n];
    }

    return 0;
}