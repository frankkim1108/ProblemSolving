#include<iostream>
#include<vector>
using namespace std;
int main() {
	int T; cin >> T;
	while (T--) {

		int eggs[100001] = { 0, };
		vector<int> plates;

		eggs[0] = 0;

		int N, M;
		cin >> N >> M;
		
		for (int i = 0; i < M; i++) {
			int plate;
			cin >> plate;
			plates.push_back(plate);
		}
		
		for (int i = 1; i <= N; i++) {
			eggs[i] = 100000;
		}

		for (int i = 0; i < plates.size(); i++) {
			for (int j = 1; j <= N; j++) {
				if (j - plates[i] >= 0)
				{
					if(eggs[j] > eggs[j-plates[i]] + 1)
						eggs[j] = eggs[j - plates[i]] + 1;
				}
			}
		}
		if (eggs[N] < 100000)
			cout << eggs[N] << "\n";
		else cout << 0 << "\n";
	}
}