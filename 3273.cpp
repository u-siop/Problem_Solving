#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size, temp, x, count = 0;
    vector<int> arr;

    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> x;

    sort(arr.begin(), arr.end());

    int l = 0, r = size - 1;
    while (l < r)
    {
        if (arr[l] + arr[r] == x)
            l++, r--, count++;
        else if (arr[l] + arr[r] > x)
            r--;
        else if (arr[l] + arr[r] < x)
            l++;
    }

    cout << count;

    return 0;
}