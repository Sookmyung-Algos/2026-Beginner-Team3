#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, P, count = 0;
    cin >> N >> K;
    vector<int> v(N+1);

    for (int i = 2; i <= N; i++) {
        v[i] = i;
    }

    for (int i = 2; i <= N; i++) {
        if (v[i] == 0) continue;
        for (int j = i; j <= N; j += i){
            if (v[j] == 0) continue;
            v[j] = 0;
            count++;
            if (count == K) {
                cout << j << "\n";
                return 0;
            }
        }
    }

}