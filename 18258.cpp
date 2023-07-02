#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> queue;
    string operation;
    size_t space = operation.rfind(' ');
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> operation;
        if (operation.find("push") != string::npos)
        {
            int num = stoi(operation.substr(space + 1));
            queue.push(num);
        }
        else if (operation == "pop")
        {
            queue.pop();
        }
        else if (operation == "size")
        {
            cout << queue.size() << endl;
        }
        else if (operation == "empty")
        {
            cout << queue.empty() << endl;
        }
        else if (operation == "front")
        {
            cout << queue.front() << endl;
        }
        else if (operation == "back")
        {
            cout << queue.back() << endl;
        }
    }

    return 0;
}