#include <iostream>
using namespace std;

int main() {

	int T; cin >> T;
	while (T--) {
		int arr[10000];
		for (int i = 0; i < 10000; i++) {
			arr[i] = -1;
		}
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n - 1; i++) {
			int v1, v2; cin >> v1 >> v2;
			arr[v2] = v1;
		}
		for (int i = 0; i < k; i++) {
			bool check[10000] = {false};
			int q1, q2;
			cin >> q1 >> q2;
			check[q1] = true;
			while (arr[q1] != -1) {
				q1 = arr[q1];
				check[q1] = true;
			}
			while (check[q2] == false) {
				q2 = arr[q2];
			}
			cout << q2 << "\n";
		}
	}
}