#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> a(N);

    int high = 0;

    for (int i = 0; i < N; i++) {
        cin >> a[i];

        if (a[i] > high) {
            high = a[i];
        }
    }

    long long M;
    cin >> M;

    int low = 0;
    int answer = 0;

    while (low <= high) {

        int mid = (low + high) / 2;

        long long sum = 0;

        for (int i = 0; i < N; i++) {
            if (a[i] > mid) {
                sum += mid;
            }
            else {
                sum += a[i];
            }
        }

        if (sum <= M) {
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