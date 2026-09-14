#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m,sum=0;
    cin >> n;

    vector<int> vec(n);
    for (int i=0; i<n; i++) {
        cin >> vec[i];
        sum += vec[i];
    }

    cin >> m;

    sort(vec.begin(), vec.end());

    int left = 0;
    int right = vec[n-1];
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        int total = 0;

        for (int x : vec) {
            total += min(x, mid);
        }

        if (total <= m) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << answer;
}