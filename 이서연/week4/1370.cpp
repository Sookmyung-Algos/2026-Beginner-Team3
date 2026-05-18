#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Meeting {
    int num;
    int start;
    int end;
};

bool cmp(Meeting a, Meeting b) {
    if (a.end == b.end) {
        return a.start < b.start;
    }
    return a.end < b.end;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Meeting> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].num >> v[i].start >> v[i].end;
    }

    sort(v.begin(), v.end(), cmp);

    vector<int> answer;
    int lastEnd = 0;

    for (int i = 0; i < N; i++) {
        if (v[i].start >= lastEnd) {
            answer.push_back(v[i].num);
            lastEnd = v[i].end;
        }
    }

    cout << answer.size() << '\n';

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }

    return 0;
}