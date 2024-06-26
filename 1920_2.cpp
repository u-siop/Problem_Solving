#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int a[100002];
int arr[1000002];

int func(int k){
    int mid = n/2;
    if(k>mid){
        mid = (mid+n)/2;
    }else if(k<mid){
        mid = mid/2;
    }else{
        return 1;
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> arr[i];
    }

    sort(a, a+n);

    for(int i = 0; i < m; i++){
        cout << func(arr[i]) << '\n';
    }

    return 0;
}
