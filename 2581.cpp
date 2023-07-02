#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int main()
{
    int prime[MAX];
    int n, m;
    int sum = 0;
    cin >> n >> m;

    int index[m - n];

    prime[0] = 1;
    prime[1] = 2;
    prime[2] = 3;
    int k = 3, l = 0, j = 1; // k : prime 중 값을 가지고 있는 최대 index, l : n과 m 사이의 소수의 갯수, j : 소수인지 아닌지 판별 반복문

    if (n <= 3)
    {
        if (m <= 3)
        {
            for (int i = n; i <= m; i++)
            {
                index[l++] = i;
            }
        }
        else
        {
            index[0] = 1, index[1] = 2, index[2] = 3, l = 3;
            for (int i = 4; i <= m; i++)
            {
                for (j = 1; j < k; j++)
                {
                    if (i % prime[j] == 0)
                        break;
                }
                if (j >= k - 1)
                {
                    prime[k++] = i;
                    index[l++] = i;
                }
            }
        }
    }
    else
    {
        for (int i = 4; i <= n; i++)
        {
            for (j = 1; j < k; j++)
            {
                if (i % prime[j] == 0)
                    break;
            }
            if (j >= k - 1)
                prime[k++] = i;
        }

        for (int i = n; i <= m; i++)
        {
            for (j = 1; j < k; j++)
            {
                if (i % prime[j] == 0)
                    break;
            }
            if (j >= k - 1)
            {
                prime[k++] = i;
                index[l++] = i;
            }
        }
    }

    if (l == 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        for (int i = 0; i < l; i++)
        {
            sum += index[i];
        }
        cout << sum << endl
             << index[0] << endl;
    }

    return 0;
}

// #include <iostream>
// using namespace std;

// int main()
// {
//     int M, N;
//     int sum = 0, min = -1;
//     int cnt = 0;
//     cin >> M >> N;

//     for (int i = M; i <= N; i++)
//     {
//         for (int div = 1; div <= i; div++)
//         {
//             if (i % div == 0)
//                 cnt++;
//         }
//         if (cnt == 2)
//         {                  // i가 소수일 때
//             if (min == -1) // 저장된 소수의 최솟값이 없을 때
//                 min = i;
//             sum += i;
//         }
//         cnt = 0;
//     }
//     if (min == -1)
//         cout << -1 << '\n';
//     else
//         cout << sum << '\n'
//              << min << '\n';
// }