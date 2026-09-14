#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,q;
    cin >> n >> q;

    vector<int> vec(n);
    for (int i=0; i<n; i++) {
        cin >> vec[i];
    }
    
    vector<int> quest(q);
    for (int i=0; i<q; i++) {
        cin >> quest[i];
    }

    for (auto it = quest.begin(); it != quest.end(); it++) {
        int x = *it;

        if (binary_search(vec.begin(), vec.end(), x)) {
            cout << x << '\n';
        }
        else {
            if (upper_bound(vec.begin(), vec.end(), x) == vec.begin()) {
                cout << vec[0] <<'\n';
            }
            else if (upper_bound(vec.begin(), vec.end(), x) == vec.end()) {
                cout << vec[n-1] <<'\n';
            }
            else {
                int low = *(--upper_bound(vec.begin(), vec.end(), x));
                int high = *upper_bound(vec.begin(), vec.end(), x);

                if (x-low > high-x) {
                    cout << high << '\n';
                }
                else {
                    cout << low << '\n';
                }
            }
            
        }
    }
}