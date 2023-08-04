#include <bits/stdc++.h>
using namespace std;

// time limit : 1sec
// memory limit : 256MB
// 1<= n <= 1,000
int D[1003];

int main(){
    int n;
    cin >> n;           // 2*1 : 2개가 한 쌍, 1*2 : 1개씩, combination? permutation?

    D[1] = 1;
    D[2] = 2;

    for(int i=3; i<=n; i++){
        D[i] = (D[i-1] + D[i-2]) % 10007;
    }

    cout << D[n]<< endl;
    return 0;
}