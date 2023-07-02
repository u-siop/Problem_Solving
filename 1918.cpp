#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    stack<char> stack;
    vector<char> postfix;

    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] < 65 || str[i] > 122)
        {
            if (str[i] == 43 || str[i] == 45) // + or -
            {
                for (int j = i; j < str.size(); j++)
                {
                    if (str[j] == 42 || str[j] == 47 || str[j] == 40)
                    {
                        stack.push(str[i - 1]);
                        stack.push(str[i]);
                    }
                    else
                    {
                        postfix.push_back(str[i - 1]);
                        postfix.push_back(str[i + 1]);
                        postfix.push_back(str[i]);
                    }
                }
            }
            else if (str[i] == 42 || str[i] == 47) // * or /
            {
                for (int j = i; j < str.size(); j++)
                {
                    if (str[j] == 40)
                    {
                        stack.push(str[i - 1]);
                        stack.push(str[i]);
                    }
                    else
                    {
                        postfix.push_back(str[i - 1]);
                        postfix.push_back(str[i + 1]);
                        postfix.push_back(str[i]);
                    }
                }
            }
            else if (str[i] == 40) // (
            {
                for (int j = i; j < str.size(); j++)
                {
                    postfix.push_back(str[i - 1]);
                    postfix.push_back(str[i + 1]);
                    postfix.push_back(str[i]);
                }
            }
            // else if (str[i] == 41)   // ) 이게 먼저 나올 수가 없음
            // {
            // }
        }
    }

    for (int i = 0; i < stack.size(); i++)
    {
        }
}