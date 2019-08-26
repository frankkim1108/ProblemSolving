#include <iostream>
#include<vector>

using namespace std;

#define MOD 1013
#define MOD2 37

int hash1(int key) {
	return key % MOD;
}
int hash2(int key) {
	return MOD2 - (key % MOD2);
}

int main() {
	int count = 0;
	int T;
	cin >> T;
	int winner = 0;
	while (T--) {
		int N, i;
		winner = 0;
		int drawer[1013] = { 0, };
		cin >> N >> i;

		vector<int> people(N);
		drawer[i] = -1;

		for (int k = 0; k < N; k++) {
			cin >> people[k];
		}

		for (int k = 0; k < N; k++) {
			int x = people[k];
			count = 0;
			int F = hash1(x);
			int S = hash2(x);

			if (drawer[F] == 0)
			{
				drawer[F] = 1;
			}
			else {
				if (drawer[F] == 1) {
					F = (F + S) % MOD;
					count++;
					while (drawer[F] == 1) {
						count++;
						F = (F + S) % MOD;
					}
					if (drawer[F] == -1) {
						winner = x;
						break;
					}
				}
				else if (drawer[F] == -1) {
					winner = x;
					break;
				}
			}
		}
		if (winner == 0) cout << "N\n";
		else cout << (100 - count) * 10000 << '\n';
	}
}