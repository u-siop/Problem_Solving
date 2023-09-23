#include <bits/stdc++.h>
using namespace std;

vector<string> split(string& s, string sep){
    vector<string> ret;
    int pos = 0;
    while(pos < s.size()){
        int nxt_pos = s.find(sep, pos);
        if(nxt_pos == -1) nxt_pos = s.size();
        if(nxt_pos - pos > 0)
            ret.push_back(s.substr(pos, nxt_pos - pos));
        pos = nxt_pos + sep.size();
    }

    return ret;
}

int detect(string& s){
    string ret = "_";
    if(s.find(ret) != string::npos) return 0; // this string is cpp
    else{
        int pos = 0;
        while(pos < s.size()){
            if(isupper(s[pos++])){
                return 1;                     // this string is java
            }
        }
        return 2;                             // error
    }
}


int main(){
    string s;
    cin >> s;
    int flag = detect(s);
    switch(flag){
    case 0:
        split(s, "_");
        break;
    case 1:
        break;
    case 2:
        cout << "Error!" <<'\n';
        break;
    }


    return 0;
}

