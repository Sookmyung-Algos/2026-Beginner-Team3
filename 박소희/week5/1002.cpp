#include <iostream>
#include <vector>

using namespace std;

int euclidean(int a, int b){
    if (b == 0)
        return a;
    return euclidean(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, gcd, lcm;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    gcd = lcm = v[0];
    
    for (int i = 0; i < N; i++){
        gcd = euclidean(gcd, v[i]);
        lcm = lcm / euclidean(lcm, v[i]) * v[i];
    }
    cout << gcd << ' ' << lcm;

    return 0;
}