#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, k, ans;
    string line;

    cin >> N >> k >> line;
    
    vector<bool> used(N, false);


    for (int i = 0; i < N; i++) {
        if (line[i] == 'P'){
            for (int j = max(0, i - k); j <= min(N - 1, i + k); j++){
                if (line[j] == 'H' && !used[j]){
                    used[j] = true;
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans;

    return 0;
}