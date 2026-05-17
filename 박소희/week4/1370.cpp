#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Meeting {
    int id, s, e;
};

bool cmp(const Meeting& a, const Meeting& b) {
    if (a.e != b.e) return a.e < b.e; // 종료시간 오름차순
    return a.s < b.s; // 종료시간 같으면 시작시간 오름차순
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<Meeting> m(N);

    for (int i = 0; i < N; i++) {
        cin >> m[i].id >> m[i].s >> m[i].e;
    }

    sort(m.begin(), m.end(), cmp);
    
    vector<int> result; // 선택된 회의 번호 저장할 벡터
    int last_end = -1; // 마지막 선택 회의의 종료시간

    for (int i = 0; i < N; i++) {
        if (m[i].s >= last_end) { //시작시간이 마지막 종료시간보다 크면
            result.push_back(m[i].id); // 회의번호 result에 넣고
            last_end = m[i].e; // last_end 갱신
        }
    }

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        if (i) cout << " "; // 첫번째 앞에 공백 안 넣기 위함
        cout << result[i];
    }
    return 0;
}