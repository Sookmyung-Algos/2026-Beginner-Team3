#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return true;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return false;
}

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

    bool find = false;
    for (int i = 0; i < Q; i++) {
        if (binarySearch(a, b[i]) == false) {
            cout << b[i] << " ";
            find = true;
        }
    }

    if (find == false) {
        cout << -1;
    }
    return 0;
}