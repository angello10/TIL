#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
	string key;
	string sentence;
	cin >> key >> sentence;
	
	int len = key.length();
	
	int arr1[len];
	char arr2[len];
	
	for (int i = 0;i < len;i++) arr2[i] = key[i];
	sort(arr2, arr2 + len);
	
	int order[len];
	for (int i = 0;i < len;i++) {
		for (int n = 0;n < len;n++) {
			if (key[n] == arr2[i]) {
				order[n] = i;
				key[n] = 32;
				break;
			}
		}
	}
	
	int len2 = sentence.length();
	
	for (int i = 0;i < len2 / len;i++) {
		for (int n = 0;n < len;n++) {
			cout << sentence[i + order[n] * len2 / len];
		}
	}
	return 0;
}