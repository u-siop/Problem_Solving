//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    vector<int> broad;
    int h, w;
    int temp;
    int rainfall = 0;

    cin >> h >> w;
    for (int i = 0; i < w; i++) {
        cin >> temp;
        broad.push_back(temp);
    }

    for (int i = 0; i < broad.size(); i++) {
        if (broad[i] > 0) {
            for (int j = i + 1; j < broad.size(); j++) {
                if (broad[j] >= broad[i]) {                 // 1 0 2 or 2 1 3
                    if (i + 1 == j) continue;
                    else {
                        for (int k = i + 1; k < j; k++) {
                            rainfall += broad[i] - broad[k];
                        }
                        i = j-1;
                        break;
                    }
                }
                else {
                    if (i + 1 == j) continue;
                    else {                               // 3 0 1 or 3 1 2
                        if (j == (broad.size() - 1)) {
                            for (int k = i + 1; k < j; k++) {
                                rainfall += (broad[j] - broad[k]);
                            }
                        }
                            if (broad[j + 1] >= broad[j]) continue;
                        for (int k = i + 1; k < j; k++) {
                            rainfall += (broad[j] - broad[k]);
                        }
                        i = j-1;
                        break;
                    }
                }
            }
        }
    }

    cout << rainfall << endl;
    return 0;
}