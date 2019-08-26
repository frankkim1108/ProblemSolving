#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int height = 0;
	int number = 0;
	bool visited = false;
	vector<Node*> adj;
};


bool compare(Node* a, Node* b) {
	return a->height < b->height;
}

void DFS(vector<Node*> &v, Node* a) {
	a->visited = true;
	cout << a->number << "\n";

	sort(a->adj.begin(), a->adj.end(), compare);

	for (int i = 0; i < a->adj.size(); i++) {
		if (a->adj[i]->visited == false) {
			DFS(v, a->adj[i]);
		}
	}
}


int main() {
	int T;
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N >> M;

		vector<Node*> V;

		for (int i = 0; i < N; i++) {
			Node* newNode = new Node();
			cin >> newNode->height;
			newNode->number = i;
			V.push_back(newNode);
		}

		for (int i = 0; i < M; i++) {

			int N1, N2;
			cin >> N1 >> N2;

			V[N1]->adj.push_back(V[N2]);
			V[N2]->adj.push_back(V[N1]);
		}

		sort(V.begin(), V.end(), compare);

		for(int i = 0; i < V.size(); i++) {
			if(V[i]->visited == false)
			DFS(V, V[i]);
		}

	}
}