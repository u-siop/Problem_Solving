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

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   while(true){
//     string a;
//     getline(cin, a);
//     if(a == ".") break;
//     stack<char> s;
//     bool isValid = true;
//     for(auto c : a){
//       if(c == '(' || c == '[') s.push(c);
//       else if(c == ')'){
//         if(s.empty() || s.top() != '('){         // At this point, there is "Shortcut-circuit evalutaion" that if the s.empty() is right, go to execution right away, before check s.top(0,
//           isValid = false;
//           break;
//         }
//         s.pop();
//       }
//       else if(c == ']'){
//         if(s.empty() || s.top() != '['){
//           isValid = false;
//           break;
//         }
//         s.pop();
//       }
//     }
//     if(!s.empty()) isValid = false;
//     if(isValid) cout << "yes\n";
//     else cout << "no\n";
//   }
// }