#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,v;
    cin >> a >> b >> v;
    int ans = 1;
    ans += ceil((double)(v-a)/(a-b));
    if(a>=v) ans = 1;
    cout << ans << endl;
    return 0;
}