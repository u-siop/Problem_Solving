#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

// 1,2,3,4    1,2,4,3 x   1,2  1,3   1,4, 2,1x 2,3, 2,4 ,3,4

void fact(int k)
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
            {
                // if (k == 0)
                //     arr[k] = i;
                // if (k > 0 && i > arr[k - 1])
                arr[k] = i;
                for (int j = 0; j < i; j++)
                {
                    isused[j] = 1;
                }
                isused[i] = 1;
                fact(k + 1);
                isused[i] = 0;
                for (int j = 0; j < i; j++)
                {
                    isused[j] = 0;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    fact(0);
    return 0;
}