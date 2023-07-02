#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int main()
{
    int divisor[MAX] = { 0 };
    int n, k;
    int count = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            divisor[count++] = i;
        }
    }
    cout << divisor[k] << endl;

    return 0;
}