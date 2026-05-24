#include <iostream>
#include <vector>

using namespace std;

long long get_gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long get_lcm(long long a, long long b) {
    return (a * b) / get_gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long gcd_res = arr[0];
    long long lcm_res = arr[0];

    for (int i = 1; i < n; i++) {
        gcd_res = get_gcd(gcd_res, arr[i]);
        lcm_res = get_lcm(lcm_res, arr[i]);
    }

    cout << gcd_res << " " << lcm_res << "\n";

    return 0;
}