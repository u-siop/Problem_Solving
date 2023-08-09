#include <bits/stdc++.h>
using namespace std;

// time limit : 2sec
// memory limit : 128MB
// 1<=N<=50, 0<= a,b[i] <=100;

vector<int> A;
vector<int> B;

// 1. Brute Force -> check all the possibilities -> O(n^2)
// 2. DP? -> ???
// 3. Greedy -> b의 제일 큰 값에, a의 제일 작은 값 배치 ...

int main(){
    int n;
    int a,b;
    int anw =0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        A.push_back(a);
    }
    for(int i=0; i<n; i++){
        cin >> b;
        B.push_back(b);
    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    for(int i=0; i<n; i++){
        anw += A[i] * B[n-1-i];
    }

    cout << anw << endl;

    return 0;
}