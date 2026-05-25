#include <iostream>
#include <vector>

using namespace std;

int N;
int K;
int c = 0;
vector<int>n;
int answer;

void eratos() {
	for (int i = 2; i <= N; i++) {
		n[i] = i;
	}
	for (int i = 2; i <= N; i++) {
		if (n[i] == 0) continue;
		for (int j = i; j <= N; j += i) {
			if (n[j] == 0) continue;
			n[j] = 0;
			c += 1;
			if (c == K) {
				answer = j;
				cout << answer;
				return;
			}

		}

	}
	cout << answer;
}

int main(void) {
	cin >> N >> K;
	n.resize(N + 1);
	eratos();
	return 0;
}

