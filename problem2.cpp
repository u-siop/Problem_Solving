#include <iostream>
using namespace std;

/*
int func2(int arr[],int N){
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(arr[i]+arr[j]==100) return 1;
        }
    }
    return 0;
}
*/

int func2(int arr[], int N)
{
    int occur[101] = {};
    for (int i = 0; i < N; i++)
    {
        if (occur[100 - arr[i]] == 1)
            return 1;
        occur[arr[i]] = 1;
    }

    return 0;
}

// 똑같이 짰는데 O(N^2)라는 풀이 밖에 생각이 안남
// 조금 생각하고 짰는대도 불구하고, O(N)이 있을 것 같다라는 막연한 느낌만 있었지, 막상구현을 못함