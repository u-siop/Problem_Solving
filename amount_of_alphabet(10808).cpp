#include <bits/stdc++.h>
using namespace std;

int main()
{
    char alphabet[100] = {
        0,
    };
    int count[26] = {
        0,
    };
    int i = 0;

    cin >> alphabet;

    while (alphabet[i] != 0)
    {
        count[(int)alphabet[i] - 97]++;
        i++;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << count[i] << " ";
        if (i == 25)
            cout << count[i];
    }
}

/*
#include <bits/stdc++.h>
using namespace std;

int freq[26];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for(auto c : s)
    freq[c-'a']++;
  for(int i = 0; i < 26; i++)
    cout << freq[i] << ' ';
}
*/