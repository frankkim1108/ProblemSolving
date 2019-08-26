#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Node {
public:
	long long int count;

	vector < pair<int, int> > child;

	Node() {
		this->count = 0;
	}
};

Node node[101];


void dfs(int num, long long int count) {
	if (node[num].child.empty()) {
		node[num].count = count;
	}

	for (unsigned int i = 0; i < node[num].child.size(); i++) {
		dfs(node[num].child[i].first, count * node[num].child[i].second);
	}
}

int main() {
	int T; cin >> T;
	
	while (T--) {
		int N;
		cin >> N;
		int M;
		cin >> M;
		node[N].count = 1;
		for (int i = 0; i < M; i++) {
			int miding, basicing, cnt;
			cin >> miding >> basicing >> cnt;
			node[miding].child.push_back(make_pair(basicing, cnt));
		}

		dfs(N, 1);

		for (unsigned int i = 1; i <= N; i++) {
			if (node[i].child.empty())
				cout << i << " " << node[i].count << "\n";

			node[i].child.clear();
		}
	}
}