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
Dynamic Programming�� �̿��Ͽ����ϴ�.
���� ���ڸ��� k(k = 2, 3, 4, 5, 6, 7, 8)�� N�ڸ� ��ܼ��� ������
���� ���ڸ��� k - 1, k + 1�� N - 1�ڸ� ��ܼ��� �հ� ���ٴ� ������� ���� Ǯ �� �ֽ��ϴ�.
���� ���ڸ��� 1�� ���� 9�� ������ ������ ������� ������ ������ ����ϴ�.
*/