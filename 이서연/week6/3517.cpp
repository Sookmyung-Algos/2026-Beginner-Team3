#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int Q;
    cin >> Q;

    vector<int> b(Q);
    for (int i = 0; i < Q; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < Q; i++) {
        cout << binarySearch(a, b[i]) << " ";
    }

    return 0;
}