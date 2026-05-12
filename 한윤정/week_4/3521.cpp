#include <iostream>
using namespace std;

int v[5] = {1,2,4,8,16};
int k[5];

int main() {
	int N;
	int res = 0;

	for (int i = 0; i < 5;i++) {
		cin >> k[i];
	}
	cin >> N;
	
	
	for (int j = 4; j >= 0; j--) {
		int use = min(N / v[j], k[j]); 
		res += use;
		N -= use * v[j];
	}
		
	
	if (N != 0) {
		cout<<"impossible";
	}
	else { cout << res; }
		


	return 0;
}