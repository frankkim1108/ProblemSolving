#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int country[51][51];

void BFS(int x, int y, int B, int L) {
	queue<pair<int, int> > bfs;
	bfs.push(make_pair(x, y));
	country[x][y] = 0;

	while (!bfs.empty()) {
		int x = bfs.front().first;
		int y = bfs.front().second;
		bfs.pop();

		if (x + 1 < L) {
			if (country[x + 1][y] == 1) {
				bfs.push(make_pair(x + 1, y));
				country[x + 1][y] = 0;
			}
		}
		if (x - 1 >= 0) {
			if (country[x - 1][y] == 1) {
				bfs.push(make_pair(x - 1, y));
				country[x - 1][y] = 0;
			}
		}
		if (y + 1 < B) {
			if (country[x][y + 1] == 1) {
				bfs.push(make_pair(x, y + 1));
				country[x][y + 1] = 0;
			}
		}
		if (y - 1 >= 0) {
			if (country[x][y - 1] == 1) {
				bfs.push(make_pair(x, y - 1));
				country[x][y - 1] = 0;
			}
		}
	}
}

int main() {
	int T; cin >> T;
	while (T--) {
		int counter = 0;

		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				country[i][j] = 0;
			}
		}

		int L; int B; int V;
		cin >> L >> B >> V;

		for (int i = 0; i < V; i++) {
			int x, y;
			cin >> x >> y;
			country[x][y] = 1;
		}

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < B; j++) {
				if (country[i][j] == 1) {
					BFS(i, j, B, L);
					counter++;
				}

			}

		}
		cout << counter << "\n";
	}
}



