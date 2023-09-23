#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int anw = 1;
    string s;
    cin >> s;

    if(s.find(" ") != string::npos) anw++;

    cout << anw << '\n';
    return 0;
}