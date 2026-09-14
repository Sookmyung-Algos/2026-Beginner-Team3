#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Q, x;

bool binarySearch(vector<long long>& arr, int target){
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return true;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    vector<long long> resi(N);

    for (int i=0; i<N; i++){
        cin >> resi[i];
    }
    sort(resi.begin(), resi.end());

    int cnt = 0;

    for (int i=0; i<Q; i++){
        cin >> x;
        if (!(binarySearch(resi, x))){
            cout << x << ' ';
        }
        else 
            cnt++;
    }
    if (cnt == Q)
        cout << -1 << '\n';


    
}