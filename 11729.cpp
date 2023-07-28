#include <bits/stdc++.h>
using namespace std;

bool temp = false;
int count = 0;

void hanoi(int n, int plate){              // for taking out n, n-1 to 2, n-2 to 3, n-3 to 2, ...
                                // for stacking n-1, n-2 to 1, n-3 to 2, ...
    if(n != 1){
        if(temp == false){          // blocks going to second plate
            temp = true;
        }
        else{                       // blocks going to third plate
            temp = false;
            
        }
    }
    else{
        cout << "1 3"<<endl;    // this is the most bottom block and then stacking rest of blocks
        // until this lowest 1, how can i print n-1's taking out
        return;
    }
}

int main(){
    int n;
    cin >> n;
    
    hanoi(n, 1);               // 2^n - 1
    

    return 0;
}