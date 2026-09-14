#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<int> b(Q);
    for (int i = 0; i < Q; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < Q; i++) {

        auto it = lower_bound(a.begin(), a.end(), b[i]);

        if (it == a.begin()) {
            cout << *it << "\n";
        }
        else if (it == a.end()) {
            cout << a[N - 1] << "\n";
        }
        else {
            int right = *it;
            int left = *(it - 1);

            if (b[i] - left <= right - b[i]) {
                cout << left << "\n";
            }
            else {
                cout << right << "\n";
            }
        }
    }
    return 0;
}