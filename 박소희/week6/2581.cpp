#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int A[100001];
    long long sum = 0;

    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
        sum += A[i];
    }
    cin >> M;
    sort(A, A+N);

    int low = 0;
    int high = A[N-1];
    int ans;

    if (sum <= M){
        cout << A[N-1] << '\n';
    }
    else {
        while(low <= high) {
            int mid = (low + high) / 2;
            sum = 0;

            for (int i=0; i<N; i++){
                sum += min(A[i], mid);
            }

            if (sum <= M) {
                ans = mid;
                low = mid + 1;
            }
            else    
                high = mid - 1;
        }
        cout << ans << '\n';
    }
}