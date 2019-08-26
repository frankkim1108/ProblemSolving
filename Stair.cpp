#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	long long stair[61][61];
	for (int i = 1; i <= 60; i++) {
		for (int j = 1; j <= 60; j++) {
			stair[i][j] = 0;
		}
	}
	for (int i = 1; i <= 60; i++) {
		stair[1][i] = 1;
		stair[i][1] = 1;
	}
	for (int i = 2; i <= 60; i++) {
		stair[i][i] = 2 * stair[i - 1][i - 1];
		for (int j = i+1; j <= 60; j++) {
			stair[j][i] = stair[i][i];
		}
	}
	for (int i = 2; i <= 60; i++) {
		for (int j = i+1; j <= 60; j++) {
			for (int k = 1; k <= i; k++) {
				stair[i][j] += stair[i][j - k];
			}
		}
	}

	while (T--)
	{
		int x, y;
		cin >> x >> y;

		cout << stair[y][x] << "\n";
	}
}