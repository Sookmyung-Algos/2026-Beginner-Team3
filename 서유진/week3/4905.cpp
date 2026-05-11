#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct Patient {
    string name;
    int age;
    float loss;
    bool operator< (const Patient & other)const {
        if (loss==other.loss) {
            return age < other.age;
        }
        return loss < other.loss;
    }
};


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    priority_queue<Patient> pq;
    int n=0;
    string x;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> x;
        
        if (x=="push") {
            Patient p;
            cin >> p.name >> p.age >> p.loss;
            pq.push(p);
        }
        else if (x=="pop") {
            if (!pq.empty()) {
                cout << pq.top().name <<'\n';
                pq.pop();
            }
        }
    }
}