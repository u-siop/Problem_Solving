#include<iostream>
using namespace std;

int func3(int N){
    int i=1;
    while(1){
        if(i*i==N) return 1;
        else if(i*i>N) return 0;
        else if(i*i<N) i++;
    }
}


// while문으로 썼으면서 for문으로 쓰는 것을 생각지도 못했다.