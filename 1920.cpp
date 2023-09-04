#include <bits/stdc++.h>
using namespace std;

    int arr[100005];
    int n, m;

int binarysearch(int k){
    int st = 0;
    int en = n-1;
    while(st <= en){
        int mid = (st+en)/2;
        if(arr[mid] > k){
            en = mid-1;
        }
        else if(arr[mid] < k){
            st = mid+1;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr + n);
    cin >> m;
    for(int i=0; i<m; i++){
        int num;
        cin >> num;
        cout << binarysearch(num) <<'\n';
    }

    return 0;
}