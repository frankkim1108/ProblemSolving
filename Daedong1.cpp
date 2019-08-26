#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		vector<int> city[1001];
		
		
		int N, M, K;
		cin >> N >> M >> K;

		int Min = 1000000000;
		int index = 0;
		for (int i = 0; i < N; i++) {
			int H;
			cin >> H;
			if (H <= Min) {
				Min = H;
				index = i;
			}
		}

		for (int i = 0; i < M; i++) {
			int N1, N2;
			cin >> N1 >> N2;
			city[N1].push_back(N2);
			city[N2].push_back(N1);
		}
		for (int i = 0; i < K; i++) {
			bool visited[1001] = { false, };
			int destination; cin >> destination;
			bool arrived = false;
			int price = 0;
			queue<int> BFS;
			BFS.push(index);
			visited[index] = true;
			while (!BFS.empty()) {
				int size = BFS.size();
				int top = BFS.front();
				for (int l = 0; l < size; l++) {
					top = BFS.front();
					if (top == destination) {
						arrived = true;
						break;
					}
					else {
						BFS.pop();
						for (int k = 0; k < city[top].size(); k++) {
							if (visited[city[top][k]] == false) {
								BFS.push(city[top][k]);
								visited[city[top][k]] = true;
							}
						}
					}
				}
				if (arrived)
					break;
				else
					price++;
			}
			if (arrived)
				cout << price << "\n";
			else
				cout << -1 << "\n";
		}
	}

}