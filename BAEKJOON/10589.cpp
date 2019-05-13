#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    cout << ((n / 2) + (m / 2)) << endl;
    for (int i = 1;i < n;i+=2) cout << (i + 1) << " 1 " << (i + 1) << " " << m << endl;
    for (int i = 1;i < m;i+=2) cout << "1 " << (i + 1) << " " << n << " " << (i + 1) << endl;
}