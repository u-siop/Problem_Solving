#include <bits/stdc++.h>
using namespace std;

// time limit : 2sec
// memory limit : 128MB
// N<= 100,000
// meeting time <= 2^31-1 (size of int)
// 시작 시간, 끝나는 시간 -> 최대한 회의 시간이 작은 것들
// -> 왜 가능할까?
// 2^n, n^2, n
// Brute Force, DP, Greedy
// BF : just sorting, DP : D[i] : max # of meeting when the i is end of sequence, D[i] = max(D[j]) + 1 ( j번째 회의의 끝나는 시간이 i번째 회의시작 시간 이하인 모든 j)
vector<pair<int, int>> v;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    int n;
    cin >> n;
    int temp1, temp2;
    int count = 0;
    int cur = 0;
    for(int i=0; i<n; i++){
        cin >> temp1 >> temp2;
        v.push_back({temp1, temp2});
    }

    sort(v.begin(),v.end(),compare);
    for(int i=0; i<v.size(); i++){
        if(cur > v[i].first) continue;
        count++;
        cur = v[i]. second;
    }

    // for(int i=0; i<v.size(); i++){
    //     cout<< v[i].first << " " << v[i].second << endl;
    // }

    cout << count << endl;
    
    return 0;
}