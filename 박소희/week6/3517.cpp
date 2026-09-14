#include <iostream>
#include <vector>

using namespace std;

int N, Q;
long long x;

int binarySearch(vector<long long>& arr, int target){
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<long long> A(N);

    for (int i=0; i < N; i++){
        cin >> A[i];
    }
    cin >> Q;
    for (int i=0; i < Q; i++){
        cin >> x;
        cout << binarySearch(A, x) << ' ';
    }

}