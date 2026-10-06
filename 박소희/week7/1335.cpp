#include <iostream>

using namespace std;

int N, white, blue;
int paper[129][129]; // 하얀색 - 0, 파란색 - 1

bool same(int r, int c, int sz){
    for (int i=r; i < r + sz; i++){
        for (int j = c; j < c + sz; j++)
            if (paper[i][j] != paper[r][c]) return false;
    }
    return true;
}

void cut(int r, int c, int sz) {
    if (same(r, c, sz)) {                
        paper[r][c] ? blue++ : white++;
        return;
    }
    int h = sz / 2;                      
    cut(r, c, h);   // 왼쪽 위 
    cut(r, c + h, h);   // 오른쪽 위
    cut(r + h, c, h);   // 왼쪽 아래
    cut(r + h, c + h, h);   // 오른쪽 아래
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> paper[i][j];
        }
    }
    cut(1, 1, N);
    cout << white << "\n" << blue << '\n';

}