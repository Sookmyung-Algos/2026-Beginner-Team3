#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;
    cin >> N >> S;

    long long result = 0;
    long long minPrice = 1e18;

    for (int i = 0; i < N; i++) {
        long long C, Y;
        cin >> C >> Y;

        minPrice = min(minPrice + S, C);

        result += minPrice * Y;
    }

    cout << result;

    return 0;
}