#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int sum{0};
	int min{-1};

	int exclusive_or = 0;

	for (int i = 0;i < N;i++) {
		int x;
		cin >> x;
		if (x < min || min == -1) min = x;
		sum += x;
		exclusive_or ^= x;
	}
	cout << (exclusive_or == 0 ? sum - min : 0);
}



/*
(X_1 ⊕ X_2 ⊕ ⋯ ⊕ X_k)와 (Y_1 ⊕ Y_2 ⊕ ⋯ ⊕ Y_(n-k))가 같다면,
(X_1 ⊕ X_2 ⊕ ⋯ ⊕ X_k) ⊕ (Y_1 ⊕ Y_2 ⊕ ⋯ ⊕ Y_(n-k)) = 0 입니다.

그런데 배타적 논리합은 결합 법칙을 만족하기 때문에,
X_1 ⊕ X_2 ⊕ ⋯ ⊕ X_k ⊕ Y_1 ⊕ Y_2 ⊕ ⋯ ⊕ Y_(n-k) = 0 입니다.

또, 배타적 논리합은 교환 법칙을 만족하기 때문에,
결과적으로 수열의 모든 원소의 배타적 논리합을 구한 것이 0인지 확인하면 됩니다.

만약 이 값이 0이 아닌 경우 어떤 X, Y에 대해서도 조건을 만족시키지 못하므로 0을 출력하고,
0인 경우에는 어떤 X, Y에 대해서도 조건을 만족하므로 X의 원소들의 합이 가장 큰 경우,
즉 수열에서 가장 작은 원소 하나를 제외하고 모두 X에 있는 경우를 가정하여 받을 수 있는 돈의 최댓값을 구합니다.
*/