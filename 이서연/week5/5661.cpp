#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    long long result = 1;
    for (int i = 0; i < N; i++) {
        int p, e;
        cin >> p >> e;

        result = result * (e + 1);
    }

    cout << result;
    return 0;
}