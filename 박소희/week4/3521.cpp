#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d, e, N;
    
    cin >> a >> b >> c >> d >> e >> N;

    int weights[5] = {16, 8, 4, 2, 1};
    int counts[5] = {e, d, c, b, a};
    int res = 0;

    for (int i = 0; i < 5; i++) {
        int cnt = 0;
        if (N / weights[i] < counts[i])
            cnt = N / weights[i];
        
        else 
            cnt = counts[i];
        res += cnt;
        N -= weights[i]*cnt;
        
    }
    if (N != 0){
        cout << "impossible";
        return 0;
    }
   
    cout << res;

    return 0;
}