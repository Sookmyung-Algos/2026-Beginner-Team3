#include <iostream>
#include <vector>

using namespace std;


vector<bool> is_prime;

void sieve(int n) {
    
    is_prime.assign(n + 1, true);

    
    is_prime[0] = is_prime[1] = false;

    
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    
    sieve(n);

   
    int count = 0;
    for (int i = m; i <= n; i++) {
        if (is_prime[i]) {
            count++;
        }
    }

    
    cout << count << "\n";

    return 0;
}