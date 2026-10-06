#include <iostream>
using namespace std;

const int MOD = 10000;

void fib(long long n, long long result[]) {
    if (n == 0) {
        result[0] = 0;   // F(n)
        result[1] = 1;   // F(n+1)
        return;
    }

    long long temp[2];

    fib(n / 2, temp);

    long long a = temp[0];   // F(k)
    long long b = temp[1];   // F(k+1)

    long long c = a * ((2 * b - a + MOD) % MOD) % MOD;
    long long d = (a * a + b * b) % MOD;

    if (n % 2 == 0) {
        result[0] = c;
        result[1] = d;
    }
    else {
        result[0] = d;
        result[1] = (c + d) % MOD;
    }
}

int main() {
    long long n;

    while (cin >> n) {
        if (n == -1)
            break;

        long long result[2];

        fib(n, result);

        cout << result[0] << '\n';
    }

    return 0;
}