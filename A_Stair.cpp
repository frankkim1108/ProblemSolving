#include<iostream>
using namespace std;

long long stairs [61][61];


int main()
{
	std::ios::sync_with_stdio(false);


	for (int i = 1; i < 61; i++) {
		stairs[i][1] = 1;
		stairs[1][i] = 1;
	}
	long long num = 1;
	for (int i = 1; i < 61; i++) {
		stairs[i][i] = num;
		for (int j = i; j < 61; j++) {
			stairs[j][i] = num;
		}
		num = num * 2;
	}

	for (int i = 2; i < 61; i++) {
		for (int j = i + 1; j < 61; j++) {
			long long sum = 0;
			for (int k = j - 1; k >= j - i; k-- ) {
				sum += stairs[i][k];
			}
			stairs[i][j] = sum;
		}
	}

	int N = 0;
	cin >> N;
	while (N--) {
		int x =0, y = 0;
		cin >> x >> y;

		cout << stairs[y][x] << endl;
	}

	return 0;
}