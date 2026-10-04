#include <iostream>
using namespace std;

const int MOD = 10000;

struct Matrix {
    long long a, b, c, d;
};

Matrix multiply(Matrix x, Matrix y) {
    Matrix result;

    result.a = (x.a * y.a + x.b * y.c) % MOD;
    result.b = (x.a * y.b + x.b * y.d) % MOD;
    result.c = (x.c * y.a + x.d * y.c) % MOD;
    result.d = (x.c * y.b + x.d * y.d) % MOD;

    return result;
}

Matrix power(Matrix base, long long n) {
    Matrix result = {1, 0, 0, 1};

    while (n > 0) {
        if (n % 2 == 1) {
            result = multiply(result, base);
        }

        base = multiply(base, base);
        n /= 2;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;

    while (cin >> n) {
        if (n == -1) {
            break;
        }

        if (n == 0) {
            cout << 0 << '\n';
            continue;
        }

        Matrix base = {1, 1, 1, 0};
        Matrix result = power(base, n);

        cout << result.b % MOD << '\n';
    }

    return 0;
}