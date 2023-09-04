#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> s;

int main(){
   int k, l;
   cin >> k >> l;
   for(int i=0; i<l; i++){
    string s_num;
    cin >> s_num;
    if(s.find(s_num) != s.end()){
        s.erase(s_num);
        s[s_num] = i;
    }
    else
        s[s_num] = i;
   }

   vector<pair<string, int>> slist(s.begin(), s.end());
   sort(slist.begin(), slist.end(), [](auto& a, auto& b) {return a.second < b.second;});

   int en = min(k, (int)slist.size());

   for(int i=0; i<en; i++){
    cout << slist[i].first <<'\n';
   }

   return 0;
}