#include <cstdio>

using namespace std;



template <class T>
T max(T a, T b) {
	if (a < b) a = b;
	return a;
}

template <class T>
T max(T a, T b, T c) {
	if (a < b) a = b;
	if (a < c) a = c;
	return a;
}


int main() {
	int N;
	scanf("%d", &N);

	int arr[N][N][3];
	for (int x = 0;x < N;x++) {
		for (int y = 0;y < N;y++) {
			int milk;
			scanf("%d", &milk);
			
			if (x == 0 && y == 0) {
				arr[x][y][0] = milk == 0;
				arr[x][y][1] = 0;
				arr[x][y][2] = 0;
			}
			else if (x == 0) {
				arr[x][y][0] = arr[x][y-1][0];
				arr[x][y][1] = arr[x][y-1][1];
				arr[x][y][2] = arr[x][y-1][2];
				
				if (milk == 0 || arr[x][y-1][(milk+2)%3] > 0) arr[x][y][milk] = max(arr[x][y][milk], arr[x][y-1][(milk+2)%3] + 1);
			}
			else if (y == 0) {
				arr[x][y][0] = arr[x-1][y][0];
				arr[x][y][1] = arr[x-1][y][1];
				arr[x][y][2] = arr[x-1][y][2];
				
				if (milk == 0 || arr[x-1][y][(milk+2)%3] > 0) arr[x][y][milk] = max(arr[x][y][milk], arr[x-1][y][(milk+2)%3] + 1);
			}
			else {
				arr[x][y][0] = max(arr[x-1][y][0], arr[x][y-1][0]);
				arr[x][y][1] = max(arr[x-1][y][1], arr[x][y-1][1]);
				arr[x][y][2] = max(arr[x-1][y][2], arr[x][y-1][2]);
				
				if (milk == 0 || arr[x-1][y][(milk+2)%3] > 0) arr[x][y][milk] = max(arr[x][y][milk], arr[x-1][y][(milk+2)%3] + 1);
				if (milk == 0 || arr[x][y-1][(milk+2)%3] > 0) arr[x][y][milk] = max(arr[x][y][milk], arr[x][y-1][(milk+2)%3] + 1);
			}
		}
	}
	printf("%d", max(arr[N-1][N-1][0], arr[N-1][N-1][1], arr[N-1][N-1][2]));
	return 0;
}


/*
dp를 이용하여 풀어줍니다.
시작은 반드시 딸기 우유임에 주의합니다.
*/