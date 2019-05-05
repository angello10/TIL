#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[N][10];

    for (int i = 0;i < 10;i++) 
        arr[0][i] = 1;

    for (int i = 1;i < N;i++) {
        for (int j = 0;j < 10;j++) {
            if (j == 0) arr[i][j] = arr[i-1][j+1] % 1000000000;
            else if (j == 9) arr[i][j] = arr[i-1][j-1] % 1000000000;
            else arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % 1000000000;
        }
    }
    long sum{0};
    for (int i = 1;i < 10;i++)
        sum += arr[N-1][i];
    cout << sum % 1000000000;
}

/*
Dynamic Programming을 이용하였습니다.
제일 앞자리가 k(k = 2, 3, 4, 5, 6, 7, 8)인 N자리 계단수의 갯수는
제일 앞자리가 k - 1, k + 1인 N - 1자리 계단수의 합과 같다는 관계식을 만들어서 풀 수 있습니다.
제일 앞자리가 1일 때와 9일 때에는 유사한 방식으로 별도로 계산식을 만듭니다.
*/