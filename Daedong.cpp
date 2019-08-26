#include <iostream>
#include <vector>
#include <queue>
using namespace std;





int main()
{
	int T = 0; cin >> T;
	while (T--) {
		
		vector<int> city[1001];
		int N = 0;
		int M = 0;
		int K = 0;
		cin >> N >> M >> K;
		int min = 1000000000;
		int root = 0;
		for (int i = 0; i < N; i++) {
			int height = 0;
			cin >> height;
			if (min > height) {
				min = height;
				root = i;
			}
		}

		for (int i = 0; i < M; i++) {
			int num1 = 0, num2 = 0;
			cin >> num1 >> num2;

			city[num1].push_back(num2);
			city[num2].push_back(num1);
		}

		for (int i = 0; i < K; i++) {
			int count = 0;
			bool visit[1001] = {false, };
			int question;
			bool foundit = false;
			cin >> question;
			queue<int> bfs;
			bfs.push(root);
			visit[root] = true;

			while (!bfs.empty()) {
				
				int size = bfs.size();
				
				for (int i = 0; i < size; i++) {
					for (int i = 0; i < city[bfs.front()].size(); i++) {
						if (visit[city[bfs.front()][i]] == false) {
						bfs.push(city[bfs.front()][i]);
						visit[city[bfs.front()][i]] = true;
					}
					
				}
					if (bfs.front() == question) {
						cout << count << "\n";
						foundit = true;
						break;
					}
					else {
						
						bfs.pop();
						
						
					}
				}
				if (foundit == true)
					break;
				else
				count++;
				
			}

			if (foundit == false) {
				cout << -1 << "\n";
			}
		}
	}
}