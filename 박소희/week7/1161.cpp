#include <iostream>

using namespace std;

int n;

void Hanoi(int n, int start, int mid, int dest){
    if (n == 1)
        cout << n << " : " << start << " -> " << dest << "\n";
    else{
        Hanoi(n-1, start, dest, mid);
        cout << n << " : " << start << " -> " << dest << "\n";
        Hanoi(n-1, mid, start, dest);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    Hanoi(n, 1, 2, 3);
    return 0;
}