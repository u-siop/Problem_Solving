#include <bits/stdc++.h>

using namespace std;

int heap[100005];
int size = 0;

void push(int x){
    size++;
    heap[size] = x;
    int idx = size;
    while(index != 1){
        int par = index/2;
        if(heap[par] <= heap[index]) break;
        swap(heap[par], heap[index]);
        index = par;
    }
}

int top(){
    return heap[1];
}

void pop(){
    heap[1] = heap[size--];
    int index = 1;
    while(2*index <= size){
        int lc = 2*index, rc = 2*index+1;
        int min_child = lc;
        if(rc <= size && heap[rc] < heap[lc]) min_child = rc;
        if(heap[index] <= heap[min_child]) break;
        swap(heap[index], heap[min_child]);
        index = min_child;
    }
}

void test(){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    test();

    return 0;
}