#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int ans[10];
bool isused[10];

void bt(int k){
    if(k == m){
        for(int i = 0; i < m; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';

        return;
    }

    for(int i = 1; i <= n; i++){
        if(!isused[i]){
            ans[k] = i;
            isused[i] = 1;
            bt(k+1);
            isused[i] = 0;
        }
    }


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    bt(0);

    return 0;
}