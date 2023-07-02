#include <iostream>
using namespace std;

int func4(int N){
    int base=2;
    int result=1;
    for(int i=1;;i++){
        result*=base;
        if(result>N) return result/2;
    }
}

// 이번에는 for문으로만 짜봐야지! 했다가 while문을 놓쳤네