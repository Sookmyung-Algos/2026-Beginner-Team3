#include <iostream>
#include <vector>

using namespace std;

int euclidean(int a, int b){
    if (b == 0)
        return a;
    return euclidean(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, gcd;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];
 
    for(int i = 1; i < N; i++){
        gcd = euclidean(v[0], v[i]);
        cout << v[0]/gcd << "/" << v[i]/gcd << "\n";
    }


    return 0;
}