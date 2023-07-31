#include <bits/stdc++.h>
using namespace std;

int count = 0;

int z(int n, int r, int c){                      // (1<<n) == (1<<n-1) {lu, ld, ru, rd}
    if(n==0){
        return 0;
    }
    int half = 1<<(n-1);

    if(r<half && c<half){
        return z(n-1, r, c);
    }                // half {lu}
    else if(r<half && c>=half){
        return half*half + z(n-1,r, c-half);
    }          // ld
    else if(r>=half && c<half){
        return 2*half*half + z(n-1, r-half , c);
    }          // ru
    else{                                         // rd
        return 3*half*half + z(n-1,r-half, c-half);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,r,c;
    cin >> n >> r >> c;                 // (r,c)가 어디에 속하는 지 먼저 파악해야하나?
    // r : 2^n-1{0,1,2,3} , c : 2^n-1{0,1,2,3}
    cout<< z(n, r, c);

}