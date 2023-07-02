#include <iostream>
using namespace std;

int main(){
    int sum=0;
    int n=34567;
    for(int i=1;i<=n;i++){
        if(i%3==0 || i%5==0){
            sum+=i;
        }
    }

    cout<<sum<<endl;
}

// 참나 여기서도 실수를 하네 ㅋㅋㅋㅋㅋ
// N보다 작은 수 중 3의 배수, 5의 배수를 모두 더하는 문제인데, i=0 대입, i<N 이것도 참... 생각 없이 코드 짰다.
// 함수도 main()이 아니라 func1(int N) 짜라고 했는데, main()에다가 짜버리고 ㅎㅎ...