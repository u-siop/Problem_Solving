#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int fibo[42][42];
int t, num;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    fibo[0][0] = 1;
    fibo[1][1] = 1;

    for(int i = 2; i <= 40; i++){
        fibo[i][0] = fibo[i-1][0] + fibo[i-2][0];
        fibo[i][1] = fibo[i-1][1] + fibo[i-2][0];
    }

    cin >> t;
    while(t--){
        cin >> num;
        cout << fibo[num][0] << " " << fibo[num][1] << '\n';
    }

    return 0;
}
