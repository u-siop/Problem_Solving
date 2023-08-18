// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// n까지의 숫자중 m개 선택 -> 순열, 중복 x, 사전 순으로
// 1,2,3,4  \n 1,2,4,3 \n 1,3,2,4

int n, m;
int arr[10];
bool isused[10];

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!isused[i])
        {
            arr[k] = i;
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    func(0);
}
