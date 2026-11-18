#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> wires(N);
    for (auto& wire : wires) {
        cin >> wire.first >> wire.second;
    }

    sort(wires.begin(), wires.end());

    vector<int> tails;
    for (const auto& wire : wires) {
        int b = wire.second;
        auto it = lower_bound(tails.begin(), tails.end(), b);

        if (it == tails.end()) {
            tails.push_back(b);
        }
        else {
            *it = b;
        }
    }

    int lisLength = static_cast<int>(tails.size());
    cout << N - lisLength << '\n';
    return 0;
}