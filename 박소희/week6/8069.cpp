#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q, target;
    int A[500001];

    cin >> N >> Q;

    for (int i=0; i<N; i++)
        cin >> A[i];

    for (int i=0; i<Q; i++){
        cin >> target;
        int idx = std::lower_bound(A+0, A+N, target) - A;
        if (A[idx] != target){
            if (idx == 0)
                cout << A[0] << '\n';
            else if (abs(A[idx-1]-target) > abs(A[idx]-target))
                cout << A[idx] << '\n'; 
            else 
                cout << A[idx-1] << '\n';
        }
        else
            cout << A[idx] << '\n';
    }
}