#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int freq[2000002];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        if(num < 0){
            freq[2*num]++;
        }else if(num > 0){
            freq[2*num-1]++;
        }else{
            freq[0]++;
        }
        
    }

    for(int i=2*n; i>=2; i-=2){
        for(int j=0; j<freq[i]; j++){
            cout << freq[i] << '\n';
        }
    }
    if(freq[0] > 0){
        for(int i=0; i<freq[0]; i++){
            cout << "0\n";
        }
    }
    for(int i=0; i<=2*n-1; i++){
        for(int j=0; j<freq[i]; j++){
            cout << freq[i] << '\n';
        }
    }

    return 0;
}
