#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    int x[200001];
    cin >> N >> K;

    for (int i=0; i<N; i++){
        cin >> x[i];
    }

    sort(x, x+N);

    int low = 1;
    int high = x[N-1] - x[0];
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        int count = 1;
        int last = x[0];

        for (int i = 1; i < N; i++) {
            if (x[i] - last >= mid) {
                count++;
                last = x[i];
            }
        }

        if (count >= K) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << ans;

}