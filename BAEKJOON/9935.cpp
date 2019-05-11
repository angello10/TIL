#include <iostream>
#include <string>

using namespace std;


int main() {
    string str;
    getline(cin, str);

    string p;
    getline(cin, p);

    int N = str.size();
    int M = p.size();
    int idx = M - 1;

    for (int i = M - 1;i < N;i++) {
        str[idx] = str[i];
        if (i >= M - 1) {
            int j;
            for (j = M - 1;j >= 0;j--) {
                if (str[idx + j - (M - 1)] != p[j]) break;
            }
            if (j == -1) {
                idx -= M;
            }
        }
        idx++;
    }
    if (idx == 0) cout << "FRULA";
    else {
        for (int i = 0;i < idx;i++) cout << str[i];
    }
}

/*
폭발 문자열의 길이를 M, 문자열의 길이를 N이라 합니다.


i와 idx를 M - 1로 초기화 해줍니다.


idx와 i를 계속 1씩 늘리면서 i가 N 이상이 될 때까지 1, 2번 작업을 수행합니다.


1. 문자열의 idx 번째 문자를 i번째 문자로 덮어 씌웁니다.

2. idx에서부터 idx - (M - 1)까지 순으로 비교하면서 부분 문자열이 폭발 문자열과 일치하는지 확인합니다.
이 과정에서 폭발 문자열을 발견하면 idx를 M만큼 줄입니다.
(1번 작업에 의해 idx - (M - 1)부터 idx까지의 부분 문자열을 제거하는 것과 같은 의미를 갖게 됩니다.)


idx가 0이면 FRULA를 출력합니다.
idx가 0이 아니라면 0부터 idx까지의 부분 문자열을 출력합니다.
*/