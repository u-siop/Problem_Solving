#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    unsigned int room_num;
    int max = 0;
    int index = 0;
    int i = 0;
    cin >> room_num;

    int count[10] = { 0 };
    while (1)
    {
        count[room_num % 10]++;
        room_num = room_num / 10;
        if (room_num == 0)
            break;
    }

    int sixNine = (count[6] + count[9] + 1) / 2;
    count[6] = sixNine;
    count[9] = sixNine;

    for (int i = 0; i < 10; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            index = i;
        }
    }
    // if (index == 6 || index == 9)
    // {
    //     max = count[6] + count[9];
    //     max = max / 2 + max % 2;
    // }   -> 반례 : 199166 max에서 1을 index로 보냈지만 이후 처리 과정에서 9966을 생각을 안 하게 됨
    //              항상 max 구하기 전에 웬만한 처리를 끝내야할 듯
    cout << max << endl;
}