#include <iostream>

using namespace std;

int main() {
    int R, C, Q;
    cin >> R >> C >> Q;

    int arr[R+1][C+1];
    for (int i = 0;i < R+1;i++) {
        for (int j = 0;j < C+1;j++) {
            if (i == 0 || j == 0) {
                arr[i][j] = 0;
                continue;
            }
            cin >> arr[i][j];
            if (i > 0) arr[i][j] += arr[i-1][j];
            if (j > 0) arr[i][j] += arr[i][j-1];
            if (i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];
        }
    }
    for (int i = 0;i < Q;i++) {
        int r1, r2, c1, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << (arr[r2][c2] - arr[r2][c1-1] - arr[r1-1][c2] + arr[r1-1][c1-1]) / ((r2 - r1 + 1) * (c2 - c1 + 1)) << endl;
    }
}

/*
arr[r][c]에 (1, 1)부터 (r, c)까지의 픽셀의 밝기의 합을 저장합니다.
임의의 요청에 대해 arr의 요소의 4개의 합으로 요청받은 구간의 밝기의 합을 표현할 수 있습니다.
*/