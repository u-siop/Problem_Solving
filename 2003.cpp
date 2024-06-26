#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int arr[10002];

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int sum = 0;
    int st = 0;
    int count = 0;

    for(int en = 0; en < n; en++){
        sum += arr[en];
        while(sum >= n){
            if(sum == n){
                count++;
                sum -= arr[st++];
            }
        }
    }

    return 0;
}
