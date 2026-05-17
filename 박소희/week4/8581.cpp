#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, x;
    vector<int> A;
    vector<int> B;
    cin >> N;

    
    for (int i = 0; i < N; i++) {
        cin >> x;
        B.push_back(x);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long sum = 0;
    for (int i = 0; i < N; i++){
        sum += (long long)A[i] * B[i];
    }
    
    cout << sum;

    return 0;
}