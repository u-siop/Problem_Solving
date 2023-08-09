#include <bits/stdc++.h>
using namespace std;

// time limit : 1sec
// memory limit : 512MB
// 2<=M<= 2* 10^5 : 20,000
// 0<=b<= 10^12 : 100,000,000,000

//ax = b (mod m) (a,m) 쌍 갯수
vector<int> DP;
int gcd(int a, int b){
    int temp, n;

    if(a<b){
        temp = a;
        a = b;
        b = temp;
    }

    while(b!=0){
        n = a%b;
        a = b;
        b = n;
    }
    return a;
}

int main(){
    int M,b;
    int count = 0;
    cin >> M >> b;

    for(int i=1; i<=M; i++){
        for (int j=2; j<=M; j++){
            DP.push_back(gcd(i,j));
        }
    }

    for(int i=0; i<=DP.size(); i++){
        if(b%DP[i] == 0){
            count++;
        }
    }

    cout << count << endl;
    return 0;
}