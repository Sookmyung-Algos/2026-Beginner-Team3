#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    int n = S.size();
    vector<int> threshold(n);
    iota(threshold.begin(), threshold.end(), 0);

    int answer = 0;

    for (int cut = 1; cut < n; ++cut) {
        char added = S[cut - 1];
        int carry = -1;

        for (int j = 0; j < n; ++j) {
            if (added == S[j] || carry > threshold[j]) {
                swap(carry, threshold[j]);
            }
        }

        int lcs = 0;
        for (int j = cut; j < n; ++j) {
            if (threshold[j] < cut) {
                ++lcs;
            }
        }

        answer = max(answer, min(cut, n - cut) - lcs);
    }

    cout << answer << '\n';
    return 0;
}