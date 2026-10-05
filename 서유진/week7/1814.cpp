#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int count = 0;

    for (int i = 1; i < N; i++) {
        int temp = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > temp) {
            A[j + 1] = A[j];
            j--;
            count++;
        }

        A[j + 1] = temp;
    }

    cout << count << '\n';

    return 0;
}