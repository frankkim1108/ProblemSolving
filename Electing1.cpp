#include <iostream>
using namespace std;
int arr[4001][4001];
int main() {
	int t; cin >> t;
	for (int i = 1; i <= 4000; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				arr[i][j] = 1;
			else {
				arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % 1000000007;
			}
		}
	}
	while (t--) {
		int a, c;
		cin >> a >> c;
		cout << arr[a][c] << endl;
	}
}