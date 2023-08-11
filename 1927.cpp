#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0;

void push(int x){
    if(sz == 0) heap[++sz] = x;
    else{
        heap[++sz] = x;
        int i = sz;
        while(i >= 1){
            if(heap[i/2]>heap[i]){
                int temp = heap[i];
                heap[i] = heap[i/2];
                heap[i/2] = temp;
                i = i/2;
            }
            else break;
        }
    }
}

int top(){
    if(sz > 0) return heap[1];
    else return 0;
}

// void pop(){
//     int temp = heap[1];
//     heap[1] = heap[sz];
//     heap[sz] = temp;
//     int i = --sz;
//     while(i>=1){
//         if(heap[i/2] > heap[i]){
//             temp = heap[i];
//             heap[1] = heap[i/2];
//             heap[i/2] = temp;
//         }
//         i = i/2;
//     }
// }
// -> what is wrong with you?
// -> until swapping top and the last element is fine, then the problem is process during swapping end to top
// -> needed to change the value top to bottom but i changed the value bottom to top it doesnt make sense

void pop(){
    heap[1] = heap[sz--];
    int idx = 1;
    // 왼쪽 자식의 인덱스 (=2*idx)가 sz 보다 크면 idx는 리프
    while(2*idx <= sz){
        int lc = 2*idx, rc = 2*idx + 1;  // left child, right child
        int min_child = lc;             // 두 자식 중 작은 인덱스를 담을 예정
        if (rc <= sz && heap[rc] < heap[lc])
            min_child = rc;
        if(heap[idx] <= heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }
}

// void test(){
//     push(5);
//     push(3);
//     push(1);
//     push(7);
//     push(2);
//     cout << top() << endl;
//     pop();
//     cout << top() << endl;

//     for(int i=1; i<=sz; i++){
//         cout << heap[i] << " ";
//     }
// }

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x == 0){
            if(sz == 0){
                cout << 0 << endl;
            }
            else{
                cout << top() << endl;
                pop();
            }
        }
        else{
            push(x);
        }
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int N;
//   unsigned int t;
//   priority_queue<unsigned int, vector<unsigned int>, greater<>> pq;

//   cin >> N;
//   for (int i = 0; i < N; i++) {
//     cin >> t;
//     if (t)
//       pq.push(t);
//     else {
//       if (pq.empty())
//         cout << "0\n";
//       else {
//         cout << pq.top() << '\n';
//         pq.pop();
//       }
//     }
//   }
// }