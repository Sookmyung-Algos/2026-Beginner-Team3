// 피보나치 (분할정복 활용)

#include <iostream>
using namespace std;

struct Mat { long long a[2][2];};   // 2*2 행렬 구조체

Mat mul(const Mat& x, const Mat& y){    // 두 행렬의 곱 반환
    Mat r = {};
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++) // x의 i행과 y의 j열 내적
                r.a[i][j] = (r.a[i][j] + x.a[i][k] * y.a[k][j]) % 10000;
        }   // r[i][j] = x[i][0]*y[0][j] + x[i][1]*y[1][j]
    }
    return r;
}

// M^n을 분할정복으로 계산
// M^(n/2)구해서 제곱
Mat power(const Mat& M, long long n){
    if (n == 0) return {{{1,0}, {0,1}}};    // M^0 = I
    Mat half = power(M, n / 2);
    Mat res = mul(half, half);

    if (n % 2 == 1) res = mul(res, M);  // n이 홀수면 M 한 번 더 곱하기

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 피보나치 점화식 F(n+1) = F(n) + F(n-1)을 행렬로 표현
    //   [F(n+1)]   [1 1] [F(n)  ]
    //   [F(n)  ] = [1 0] [F(n-1)]
    // 이걸 n번 반복하면
    //   M^n = [[F(n+1), F(n)  ],
    //          [F(n),   F(n-1)]]
    Mat M = {{{1, 1}, {1, 0}}};

    long long x;
    while (cin >> x && x != -1){
        Mat R = power(M, x);
        // M^n의 0행 1열(오른쪽 위)이 F(n)
        // n = 0이면 a[0][1] = 0 = F(0)
        cout << R.a[0][1] << '\n';
    }
    return 0;
}