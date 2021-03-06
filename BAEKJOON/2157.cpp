#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(vector<short> a, vector<short> b) {
    return a[0] < b[0];
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<short>> arr1;
    int arr2[N][M];
    for (int i = 0;i < N;i++)
        for (int n = 0;n < M;n++)
            arr2[i][n] = 0;

    for (int i = 0;i < K;i++) {
        vector<short> v{0, 0, 0};
        cin >> v[0] >> v[1] >> v[2];
        v[0] -= 1;
        v[1] -= 1;
        arr1.push_back(v);
    }
    sort(arr1.begin(), arr1.end(), compare);

    int max{0};
    for (int i = 0;i < K;i++) {
        if (arr1[i][0] > arr1[i][1]) continue;
        for (int n = 0;n < M - 1;n++) {
            int s = arr2[arr1[i][0]][n];
            if (arr1[i][0] != 0 && s == 0) continue;
            if (arr2[arr1[i][1]][n + 1] < s + arr1[i][2]) arr2[arr1[i][1]][n + 1] = s + arr1[i][2];
        }
    }
    for (int n = 0;n < M;n++) {
        if (arr2[N-1][n] > max) max = arr2[N-1][n];
    }
    cout << max;
    return 0;
}

/*
Dynamic Programming을 이용하여 풀어줍니다.
N * M 배열 arr을 만들고,
임의의 a,b,c에 대해서
arr[a-1][k] + c가 arr[b-1][k+1]보다 크면 arr[b-1][k+1]를 업데이트 해줍니다.(k는 arr[a-1][k] != 0이고, 0 ~ M-1 사이의 정수)
arr[N-1]의 요소중에서 최댓값이 구하고자 하는 답입니다. 
*/