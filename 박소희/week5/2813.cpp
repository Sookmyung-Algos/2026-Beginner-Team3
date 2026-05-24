#include <iostream>
#include <vector>

using namespace std;


int count_eratos(int m, int n) {
    // 0과 1은 소수가 아니므로 false, 나머지는 true로 초기화
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) { 
        if (is_prime[i]) { // 소수(i) 찾기
            // p의 배수들을 false로 (i*i전은 이미 다 지워짐)
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    // 개수 세기
    int count = 0;
    for (int p = m; p <= n; p++) {
        if (is_prime[p]) count++;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> M >> N;

    cout << count_eratos(M, N);

}