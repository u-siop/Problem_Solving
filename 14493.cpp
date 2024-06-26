#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> bot(n);
    for (int i = 0; i < n; ++i) {
        cin >> bot[i].first >> bot[i].second;
    }

    int cur = 0;
    cur += bot[0].second;
    int i = 1;

    while (i < n) {
        cur += 1;
        if (cur % (bot[i].first + bot[i].second) >= bot[i].second) {
            i += 1;
        } else {
            cur += (bot[i].second - cur % (bot[i].first + bot[i].second) - 1);
        }
    }
    
    cout << cur + 1 << endl;

    return 0;
}