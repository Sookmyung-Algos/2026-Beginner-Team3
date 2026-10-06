// 삽입정렬 횟수 세기

#include <iostream>

using namespace std;

int A[51], tmp[51];
int N, cnt = 0;

void MergeSort(int l, int r){
    if (l >= r) return;     // 원소가 1개 이하인 경우(basecase)
    int m = (l + r) / 2;
    MergeSort(l, m);
    MergeSort(m+1, r);

    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r){   // 왼쪽, 오른쪽 둘 다 원소가 남아있는 경우
        if (A[i] < A[j]){
            tmp[k++] = A[i++];  // 오른쪽이 더 크면 스위치 필요 없음
        }
        else {
            cnt += m - i + 1;   // 왼쪽의 A[i]~A[m]은 전부 A[j]보다 큼. 즉, 스위치 개수 m-i+1개
            tmp[k++] = A[j++];
        }
    }
    // 나머지 원소들 처리
    while (i <= m) tmp[k++] = A[i++];
    while (j <= r) tmp[k++] = A[j++];

    for (int t = l; t <= r; t++) // 정렬된 결과 A[]에 가져오기.
        A[t] = tmp[t];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    MergeSort(0, N-1);
    cout << cnt << "\n";
}