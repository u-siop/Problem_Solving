#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num)
{
    if (unused == 1) // need to initial linked_list first
    {
        dat[0] = -1; // initial fisrt
        pre[0] = -1;
        nxt[0] = addr;

        dat[addr] = num; // insert data
        pre[addr] = 0;
        nxt[addr] = -1;
        unused++;
    }
    else // already existed linked_list
    {
        int find_addr = 0;
        while (nxt[find_addr] != -1)
        {
            find_addr = nxt[find_addr];
        }
        nxt[find_addr] = addr;
        dat[addr] = num;
        pre[addr] = find_addr;
        nxt[addr] = -1;

        unused++;
    }
}

void erase(int addr)
{
    if (unused == 1)
    {
        cout << "ERROR THERE IS NO LINKED_LIST" << endl;
    }
    else
    {
        int find_addr = 0;
        while (nxt[find_addr] != addr)
        {
            if (nxt[addr] == -1)
            {
                nxt[find_addr] = -1;
                dat[addr] = -1;
                pre[addr] = -1;
                nxt[addr] = -1;
                unused--;
            }

            else if (nxt[addr] != -1)
            {
                nxt[find_addr] = nxt[addr];
                nxt[addr] = -1;
                pre[addr] = -1;
                nxt[addr] = -1;
                unused--;
            }
        }
    }
}

void travese()
{
}

void insert_test()
{
}

void erase_test()
{
}

int main()
{
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    insert_test();
    erase_test();
}