/////////////////////////////////////////////////////////////////
/*  처음에는 막대기 : r                                         */
/*           레이저 : l   ->  r*(l+1) 식을 세워 풀려고 노력하다가*/
/*    레이저를 쐈을 때, 몇 개의 막대기를 갈랐는 지만 생각          */
/*    즉, ) 기호를 보고 stack의 갯수를 더해주는 식으로            */
/////////////////////////////////////////////////////////////////

// #include <cstdio>
// int cnt = 0, ans = 0, ch, pch;
// int main() {
// 	while ((ch=getchar()) != '\n') {
// 		if (ch == '(') cnt++;
// 		else cnt--, ans += pch == '(' ? cnt : 1;
// 		pch = ch;
// 	}
// 	printf("%d", ans);
// }

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    stack<char> bar;
    int num_bar=0;
    getline(cin, s);

    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            bar.push(s[i]);
        }
        else{
            if(s[i-1]!=')' && bar.size()==1){
                bar.pop();
            }
            else{
                if(s[i-1]==')'){
                    bar.pop(); 
                    num_bar++;
                }
                else{
                    bar.pop();
                    num_bar += bar.size();
                }
            }
            // if (s[i-1] == '(') { // 레이저일 경우
            //     st.pop(); // 앞에서 막대라고 착각하고 stack에 s[i]를 넣었으므로 pop
            //     ans+=st.size(); // 막대의 개수만큼 ans에 추가
            // }
            // else { // 막대의 끝일 경우
            //     st.pop();  // 막대의 개수를 1 감소
            //     ans++; // 막대 1개가 절단된 것과 동일한 상황이므로 ans에 1 추가
            // }
        }
    }

    cout<<num_bar<<endl;

    return 0;
}