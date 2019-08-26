#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;

	while (T--) {
		int n = 0, L = 0, k = 0;

		cin >> n >> L >> k;

		vector<int> pos;
		for (int i = 0; i < n; i++) {
			int num = 0;
			cin >> num;
			if (num < 0) {
				num = num * (-1);
				pos.push_back(num);
			}
			else
				pos.push_back(L - num);
		}
		sort(pos.begin(), pos.end());

		cout << pos[k - 1] << "\n";

		pos.clear();
	}
}
