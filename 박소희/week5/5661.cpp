#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, a, b, x = 1;
    cin >> N;

    for (int i=0; i<N; i++){
        cin >> a >> b;
        x *= b+1;
    }
    
    cout << x;
}