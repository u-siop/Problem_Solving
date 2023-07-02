#include <bits/stdc++.h>
using namespace std;

char s[101];
stack<char> st;

int main(){
    int length;
    
    while (1){
        gets(s);

        if (s[0] == '.'){
            cout<<"yes"<<endl;
            break;
        }
        length = strlen(s);

        for (int i = 0; i < length; i++){
            if (s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }
            else if (s[i] == ')' || s[i] == ']'){
                if(st.empty()){
                    st.push(s[i]);
                }

                if(st.top() == '(' && s[i] == ']'){
                    break;
                }
                else if(st.top() == '[' && s[i] == ')'){
                    break;
                }

                if(st.top() == '(' && s[i] == ')'){
                    st.pop();
                }
                else if(st.top() == '[' && s[i] == ']'){
                    st.pop();
                } 
            }
        }
        if(st.size()==0) cout<<"yes"<<endl;
        else cout<<"no"<<endl;

        while( !st.empty() ) st.pop();
    }

    return 0;
}