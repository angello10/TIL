#include <cstdio>
#include <string>

using namespace std;

int main() {
    int N{ 0 };

    int A{ 0 };
    int B{ 0 };
    int C{ 0 };

    char ch;
    while((ch = getchar()) != '\n') {
        N++;
        if (ch == 'A') A++;
        else if (ch == 'B') B++;
        else C++;
    }

    if (C * 2 < B && N + 1 >= B * 2) {
        for (int i = 0;i < N;i++) {
            if (i % 4 == 1 && C > 0) {
                C--;
                putchar('C');
            }
            else if (i % 2 == 0 && B > 0) {
                B--;
                putchar('B');
            }
            else putchar('A');
        }
    }
    else if (C <= B && C * 2 >= B && N + 1 >= B + 2 * C) {
        int x = B - C;
        int y = C - x;
        for (int i = 0;i < 4 * x;i++) {
            if (i == N) break;
            if (i % 4 == 1 && C > 0) {
                C--;
                putchar('C');
            }
            else if (i % 2 == 0 && B > 0) {
                B--;
                putchar('B');
            }
            else putchar('A');
        }
        for (int i = 0;i < N - (4 * x);i++) {
            if (i % 3 == 0 && C > 0) {
                C--;
                putchar('C');
            }
            else if (i % 3 == 1 && B > 0) {
                B--;
                putchar('B');
            }
            else putchar('A');
        }
    }
    else if (C > B && N + 2 >= 3 * C) {
        for (int i = 0;i < N;i++) {
            if (i % 3 == 0 && C > 0) {
                C--;
                putchar('C');
            }
            else if (i % 3 == 1 && B > 0) {
                B--;
                putchar('B');
            }
            else putchar('A');
        }
    }
    else printf("-1");
}


/*
14243, 14238 문제입니다.

B, C의 대소관계에 따라서 BCBABCBA... 패턴 또는 CBACBA... 패턴의 합으로 순열을 만듭니다.

알고리즘을 구상하는 데에는 시간이 많이 걸리지 않았지만, 입출력 형식에 대해 착오가 있어 시간을 많이 낭비하였습니다.
*/