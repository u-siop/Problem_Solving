// #include<bits/stdc++.h>
// #include<string>
// using namespace std;

// int main(){
//     string s;
//     string prefix;
//     stack<char> st;
//     stack<int> mul;
//     stack<int> prefixopr;
//     int anw = 0;

//     getline(cin, s);

//     for(int i=0;i<s.length();i++){
//         if(s[i]=='(' || s[i] == '['){
//             st.push(s[i]);
//             if(!st.empty()){
//                 if(st.top()=='('){             // 2*
//                     mul.push(2);
//                     prefix +="(2*";
//                 }
//                 else{                          // st.top() == [, 3*
//                     mul.push(3);
//                     prefix +="(3*";
//                 }
//             }
//         }
//         else{                                   // s[i] == ) or ]
//             if(!st.empty()){
//                 if(st.top()=='('){
//                     if(s[i] == ']'){            // incorrect
//                         anw = 0;
//                         prefix +="error";
//                         break;
//                     }
//                     if(st.size() != mul.size()){
//                         anw += 2;
//                     }
//                     else{
//                         anw = anw * mul.top();
//                         mul.pop();
//                     }
//                 }
//                 else{                           // st.top() == [
//                     if(s[i] == ')'){            // incorrect
//                         anw = 0;
//                         prefix +="error";
//                         break;
//                     }
//                     if(st.size() != mul.size()){
//                         anw += 3;
//                     }
//                     else{
//                         anw = anw * mul.top();
//                         mul.pop();
//                     }
//                 }
//             }
//             else{
//                 anw = 0;
//                 prefix +="error";
//                 break;
//             }
//         }
//     }

//     for(int i=0;i<st.size(); i++){
//         st.pop();
//     }
//     cout<<anw<<endl;
//     cout<<prefix<<endl;

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     string s;
//     stack<char> st;
//     int size_paran = 0;
//     stack<int> num_st;
//     int anw = 0;
//     getline(cin,s);                 // 왜 getline을 쓸까? 다른 방법으로 받아올 수는 없을까
//     int length = s.length();        // 다른 사람들 코드 보면 s.length()를 새로운 변수에 저장하고 사용하던데, 계속 전체 길이를 계산하는 것을 방지하려고 하는걸까?
//     bool flag = false;

//     for(int i=0; i<length; i++){    
//         if(s[i] == '(' || s[i] == '['){
//             if(size_paran!=0){
//                 if(s[i-1] == ')' || s[i-1] == ']'){     // ()x, []x
//                     st.push(s[i]);
//                     size_paran++;
//                     cout<<"push value and plus"<<endl;
//                 }
//                 else{                   // (x) or [x]
//                     st.push('*');
//                     st.push(s[i]);
//                     size_paran++;
//                     cout<<"push value and mul"<<endl;
//                 }
//             }
//             else{
//                 if(flag == false){
//                     st.push(s[i]);
//                     size_paran++;
//                     cout<<"push value,  "<<st.top()<<";"<<endl;
//                 }
//                 else{

//                 }
//             }
//         }

//         else{                           // ),] 나왔을 때, 계산과 incorrect 찾아내야함
//             if(size_paran==0){          // incorrect
//                 anw = 0;
//                 cout<<"incorrect ] or )"<<endl;
//                 break;
//             }
//             else{
//                 if(st.top()=='(' && s[i]==']'){          // incorrect
//                     anw = 0;
//                     cout<<"incorrect (]"<<endl;
//                     break;
//                 }
//                 else if(st.top()=='[' && s[i] == ')'){   // incorrect
//                     anw = 0;
//                     cout<<"incorrect [)"<<endl;
//                     break;
//                 }
//                 else{
//                     if(st.top()!='*'){
//                         num_st.push((int)st.top() % 2 + 2);    // ( : 40, [: 91  -> 각각 2,3 으로
//                         st.pop();
//                         size_paran--;
//                         cout <<"pop and plus"<<endl;
//                     }
//                     else{
//                             st.pop();                   // pop *;
//                             anw = anw * ((int)st.top() % 2 + 2);
//                             st.pop();
//                             size_paran--;
//                             cout<<"pop and multiply"<<endl;
//                     }
//                 }
//                 if(size_paran == 0){ flag = true; }
//             }
            
//         }
//     }

//     cout << anw << endl;

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    stack<int> num_st;
    stack<char> st;
    int anw = 0;
    int paren_flag = 0;
    int bracket_flag =0;
    int temp1 = 0;
    int temp2 = 0;
    int length = s.length();
    bool valid = true;

    for(int i=0; i<length; i++){
        if(s[i] == '(' || s[i] == '['){
            if(s[i] == '('){ paren_flag++; }
            else{ bracket_flag++; }

            st.push(s[i]);
            if(i!=0){
                if(s[i-1]=='(' || s[i-1]=='['){
                    num_st.push(-((int)s[i]%2+2));
                }
                else{                          // (s[i-1] == ')' || s[i-1] == ']')
                    num_st.push((int)s[i]%2+2);
                }
            }
            else{
                num_st.push((int)s[i]%2+2);
            }
        }

        else{
            if(s[i]==')'){ paren_flag--; }
            else{ bracket_flag--; }
            if( st.empty() || ( st.top() == '(' && s[i] == ']') || ( st.top() == ']' && s[i] == ')') ){       // empty()가 참이라면 뒤 조건문은 확인 안 함
                valid = false;
                break;
            }
            else{
                if(paren_flag == 0 || bracket_flag == 0){
                    int st_size = num_st.size();
                    if(st_size!=1){
                        for(int j = 0; j<st_size-1; j++){
                            if(num_st.top()<0){
                                temp1 = -num_st.top();
                                num_st.pop();
                                temp2 = num_st.top() * temp1;
                                num_st.pop();
                                num_st.push(temp2);
                            }
                            else{
                                temp1 = num_st.top();
                                num_st.pop();
                                if(num_st.top()<0){
                                    temp2 = num_st.top() - temp1;
                                    num_st.pop();
                                    num_st.push(temp2);
                                }
                                else{
                                    temp2 = num_st.top() + temp1;
                                    num_st.pop();
                                    num_st.push(temp2);
                                }
                            }
                        }
                    }
                }
            }
            st.pop();
        }
    }
    if(valid && flag == 0){
        anw = num_st.top();
        num_st.pop();
    }
    else{
        anw = 0;
    }

    cout<<anw<<endl;

    return 0;
}