#include <iostream>
using namespace std;

void hanoi(int n, int from, int temp, int to) {
    if (n == 1) {
        cout << 1 << " : " << from << " -> " << to << '\n';
        return;
    }

    hanoi(n - 1, from, to, temp);

    cout << n << " : " << from << " -> " << to << '\n';

    hanoi(n - 1, temp, from, to);
}


int main() {
    int n;
    cin >> n;

    hanoi(n, 1, 2, 3);

    return 0;
}