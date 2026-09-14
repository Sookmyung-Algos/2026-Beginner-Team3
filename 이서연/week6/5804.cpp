#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<long long> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long low = 1;
    long long high = a[N - 1] - a[0];
    long long answer = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;

        int count = 1;
        long long last = a[0];

        for (int i = 1; i < N; i++) {
            if (a[i] - last >= mid) {
                count++;
                last = a[i];
            }
        }

        if (count >= K) {
            answer = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << answer;

    return 0;
}