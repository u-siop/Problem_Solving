#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    int alphabet[26] = { 0 };
    cin >> S;
    for (int i = 0; i < S.size(); i++)
    {
        alphabet[S[i] - 97]++;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << " ";
    }

    return 0;
}