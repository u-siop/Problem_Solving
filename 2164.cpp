#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp;
    cin >> n;

    queue<int> card;
    for (int i = 1; i <= n; i++)
    {
        card.push(i);
    }

    while (card.size() > 1)
    {
        card.pop();
        temp = card.front();
        card.pop();
        card.push(temp);
    }

    cout << card.front();

    return 0;
}