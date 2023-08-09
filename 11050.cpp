#include <bits/stdc++.h>
using namespace std;

// time limit : 1sec
// memory limit :256MB
typedef long long ll;
ll fact(ll n){
    if(n == 0) return 1;
    return n*fact(n-1);
}

int main(){
    ll n,k;
    cin >> n >> k;          // nCk = n! / (n-k)! k!    , 0C0 = 1, nCn = 1
    if(n==k) cout << 1;
    else{
        ll fact_n = fact(n);
        ll fact_nk = fact(n-k);
        ll fact_k = fact(k);

        cout << fact_n/(fact_nk*fact_k) << endl;
    }

    return 0;
}