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
    int n;
    scanf("%d", &n);

    int arr[10000][3];

    for (int i = 0;i < n;i++) {
    	int a;
    	scanf("%d", &a);
    	
    	if (i == 0) {
    		arr[i][0] = 0;
    		arr[i][1] = a;
    		arr[i][2] = a;
    	}
    	else if (i == 1) {
    		arr[i][0] = arr[0][1];
    		arr[i][1] = a;
    		arr[i][2] = arr[0][1] + a;
    	}
    	else {
    		arr[i][0] = max(arr[i-1][0], arr[i-1][1], arr[i-1][2]);
    		arr[i][1] = max(arr[i-1][0] + a, arr[i-1][1]);
    		arr[i][2] = max(arr[i-1][0] + a, arr[i-1][1] + a, arr[i-1][2]);
    	}
    }
    printf("%d", max(arr[n-1][0], arr[n-1][1], arr[n-1][2]));
}

/*
dp를 이용하여 풀어줍니다.
*/