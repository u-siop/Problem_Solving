#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[50002][2];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    return 0;
}
