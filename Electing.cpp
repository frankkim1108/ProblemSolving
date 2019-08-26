#include <vector>
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	long long MOD = 1000000007;
	int T;
	cin >> T;

	while (T--) {

		vector< long long > comb1 (4001);
		vector<long long > comb2(4001);


		int A, C;
		cin >> A >> C;
		if (C == 0) {
			cout << 1 << "\n";
			continue;
		}
		
		for (int i = 1; i <= A; i++) {
			comb1[i] = i;
		}
		for (int i = 2; i <= C; i++) {
			if (i % 2 == 0) {
				for (int j = 1; j <= i; j++) {
					comb2[j] = 1;
				}
				for (int j = i + 1; j <= A; j++) {
					comb2[j] = (comb1[j - 1] + comb2[j-1]) % MOD;
				}
			}
			else {
				for (int j = 1; j <= i; j++) {
					comb1[j] = 1;
				}
				for (int j = i + 1; j <= A; j++) {
					comb1[j] = (comb1[j - 1] + comb2[j - 1]) %MOD;
				}
			}
		}
		if (C % 2 == 0) {
			cout << comb2[A] << "\n";
		}
		else {
			cout << comb1[A] << "\n";
		}
		

	}
}