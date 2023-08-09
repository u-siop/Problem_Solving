#include <bits/stdc++.h>
using namespace std;

// time limit : 1sec
// memory limit : 256MB
// MAX N : 123,456
vector<int> a;
int d[300000];              // i까지 소수의 갯수
int main(){
    a.push_back(2);
    a.push_back(3);
    d[0] = 0;
    d[1] = 0;
    d[2] = 1;
    d[3] = 2;

    for(int i = 4; i<=250000; i++){
        for(int j=0; j<a.size(); j++){
            if(i%a[j]==0) break;
            if(j == a.size()-1) a.push_back(i);
        }
        d[i] = a.size();
        
    }
    int n;
    while(1){
        cin >> n;
        if( n == 0 ) break;
        cout << d[2*n] - d[n] << endl;
    }

    return 0;
}