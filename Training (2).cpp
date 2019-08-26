#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;

		vector<int> adj[10001];
		int incoming[10001] = { 0, };
		bool visited[10001] = { false, };

		for (int i = 0; i < M; i++) {
			vector<int> s;
			int num;
			cin >> num;
			for (int j = 0; j < num; j++) {
				int skill;
				cin >> skill;
				s.push_back(skill);
			}
			for (int j = 0; j < num - 1; j++) {
				adj[s[j]].push_back(s[j + 1]);
				incoming[s[j + 1]]++;
			}
		}
		priority_queue<int, vector<int>, greater<int> > start;
		for (int j = 1; j <= N; j++) {
			sort(adj[j].begin(), adj[j].end());
			if (incoming[j] == 0) {
				start.push(j);
			}
		}
		vector<int>result;
		while (!start.empty()) {
			int top = start.top();
			start.pop();
			if (visited[top] == false) {
				visited[top] = true;
				result.push_back(top);
			}
			for (int i = 0; i < adj[top].size(); i++) {
					--incoming[adj[top][i]];
					if (incoming[adj[top][i]] == 0)
						start.push(adj[top][i]);
				
			}
			
		}

		if (result.size() == N) {
			for (int i = 0; i < N; i++) {
				cout << result[i] << " ";
			}
			cout << "\n";
		}
		else
			cout << -1 << "\n";
	}
}