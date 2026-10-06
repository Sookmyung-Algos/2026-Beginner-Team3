#include <iostream>
using namespace std;

const int MAX = 100000;

int a[MAX], tmp[MAX];

long long mergeCount(int lo, int mid, int hi) {
    int i = lo;
    int j = mid + 1;
    int k = lo;

    long long count = 0;

    while (i <= mid && j <= hi) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        }
        else {
            tmp[k++] = a[j++];

            // a[i] ~ a[mid]가 모두 a[j]보다 큼
            count += (mid - i + 1);
        }
    }

    while (i <= mid)
        tmp[k++] = a[i++];

    while (j <= hi)
        tmp[k++] = a[j++];

    for (int t = lo; t <= hi; t++)
        a[t] = tmp[t];

    return count;
}

long long countInversion(int lo, int hi) {
    if (lo >= hi)
        return 0;

    int mid = (lo + hi) / 2;

    long long count = 0;

    count += countInversion(lo, mid);
    count += countInversion(mid + 1, hi);
    count += mergeCount(lo, mid, hi);

    return count;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << countInversion(0, n - 1);

    return 0;
}