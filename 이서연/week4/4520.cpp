#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    string table;
    cin >> table;

    int answer = 0;

    for (int i = 0; i < N; i++) {
        if (table[i] == 'P') {
            int start = max(0, i - K);
            int end = min(N - 1, i + K);

            for (int j = start; j <= end; j++) {
                if (table[j] == 'H') {
                    table[j] = 'X';
                    answer++;
                    break;
                }
            }
        }
    }

    cout << answer;

    return 0;
}