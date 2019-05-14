#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0;i < N;i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);

    int M;
    scanf("%d", &M);
    for (int i = 0;i < M;i++) {
        int x;
        scanf("%d", &x);
        printf("%d\n", binary_search(arr, arr + N, x));
    }
    return 0;
}