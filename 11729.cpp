#include <bits/stdc++.h>
using namespace std;

bool temp = false;
int count = 0;

void hanoi(int a, int b, int n){              // for taking out n, n-1 to 2, n-2 to 3, n-3 to 2, ...
                                // for stacking n-1, n-2 to 1, n-3 to 2, ...
    // if(n != 1){
    //     if(temp == false){          // blocks going to second plate
    //         temp = true;
    //     }
    //     else{                       // blocks going to third plate
    //         temp = false;

    //     }
    // }
    // else{
    //     cout << "1 3"<<endl;    // this is the most bottom block and then stacking rest of blocks
    //     // until this lowest 1, how can i print n-1's taking out
    //     return;
    // }

    if( n == 1){
        cout << a << ' ' << b << endl;
        return;
    }
    hanoi(a,6-a-b,n-1);
    cout<<a<<' '<<b<<'\n';
    hanoi(6-a-b,b,n-1);
}

int main(){
    int n;
    cin >> n;
    cout << (1<<n) -1 <<endl;               // 2^n - 1
    hanoi(1, 3, n);

    return 0;
}