// #include <bits/stdc++.h>
// using namespace std;

// // time limist : 1sec
// // memory limit : 256MB
// // n <= 100,000

// vector<string> s;

// int main(){
//     int n;
//     cin >> n;
//     for(int i=0; i<n; i++){
//         string s1, s2;
//         cin >> s1 >> s2;
//         if(s2 == "enter"){
//             s.push_back(s1);
//         }
//         else{
//             for(int j=0; j<s.size(); j++){
//                 if(s[j] == s1){
//                     s[j].pop_back();
//                 }
//             }
//         }
//     }

//     sort(s.begin(), s.end(), greater<string>());
//     for(auto x : s) cout << x << endl;

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

unordered_set<string> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        string name, log;
        cin >> name >> log;
        if( log == "enter") s.insert(name);
        else s.erase(name);
    }

    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for(auto x :ans) cout << x <<endl;

    return 0;
}