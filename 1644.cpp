// 1. 아리스토텔레스의 체를 이용해서 소수 배열 만들기
// 2. 연속된 소수의 합이기 때문에 가장 작은 소수부터 시작하는 포인터 하나, 그 다음을 가르키는 포인터 하나
// 3. 두 포인터 인자들의 합이 N보다 작으면 포인터 증가
// 4. N보다 크면 그 다음 작은 소수로 포인터 이동
// 5. 3,4 번 반복

#include <bits/stdc++.h>
using namespace std;

const int MXN = 4000002;
vector<bool> seive(MXN, true);
vector<int> primes;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i * i < MXN; i++)
    {
        if (!seive[i])
            continue;
        for (int j = i * i; j < MXN; j += i)
            seive[j] = false;
    }
    for (int i = 2; i < MXN; i++)
        if (seive[i])
            primes.push_back(i);
    primes.push_back(0);

    int target, s = 0, e = 1, ans = 0, tmpSum = primes[0];
    cin >> target;
    while (1)
    {
        if (tmpSum == target)
            ans++;
        if (tmpSum <= target)
            tmpSum += primes[e++];
        if (target < tmpSum)
            tmpSum -= primes[s++];
        if (e == int(primes.size()))
            break;
    }
    cout << ans;
}