#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x)
{
    dat[--head] = x;
}

void push_back(int x)
{
    dat[tail++] = x;
}

void pop_front()
{
    if (head != tail)
        head++;
    else
    {
        cout << "error" << endl;
    }
}

void pop_back()
{
    if (head != tail)
        tail--;
    else
    {
        cout << "error" << endl;
    }
}

int front()
{
    if (head != tail)
    {
        cout << dat[head] << endl;
    }
    else
    {
        cout << "error" << endl;
    }
}

int back()
{
    if (head != tail)
        cout << dat[tail - 1] << endl;
    else
    {
        cout << "error" << endl;
    }
}

void test()
{
}

int main(void)
{
    test();

    return 0;
}