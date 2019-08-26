#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	int data;
	Node* parent;
	Node* left;
	Node* right;
	bool check;
	Node() { data = -1; parent = 0; left = 0; right = 0; check = false; }
	Node(int data) { this->data = data; parent = 0; left = 0; right = 0; check = false; }
};

int main() {
	std::ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		vector<Node*> node_list;
		int n, q;
		cin >> n >> q;
		for (int i = 1; i < n; i++) {
			int parent, now;
			Node* p = new Node(); Node* n = new Node();
			cin >> parent >> now;
			if (node_list.empty()) {
				p->data = parent;
				n->data = now;
				p->left = n;
				n->parent = p;
				node_list.push_back(p);
				node_list.push_back(n);
			}
			else {
				int c = 0;
				for (size_t j = 0; j < node_list.size(); j++) {
					if (node_list[j]->data == parent) {
						p = node_list[j];
						c++;
					}
					else if (node_list[j]->data == now) {
						n = node_list[j];
						c++;
					}
					if (c == 2) break;
				}
				if (c == 0) {
					p = new Node(parent);
					n = new Node(now);
					p->left = n;
					n->parent = p;
					node_list.push_back(p);
					node_list.push_back(n);
				}
				else if (c == 1) {
					if (p->data == -1) {
						p = new Node(parent);
						p->left = n;
						n->parent = p;
						node_list.push_back(p);
					}
					else if (n->data == -1) {
						n = new Node(now);
						if (p->left == NULL) {
							p->left = n;
							n->parent = p;
						}
						else {
							p->right = n;
							n->parent = p;
						}
						node_list.push_back(n);
					}
				}
				else {
					if (p->left == NULL) {
						p->left = n;
						n->parent = p;
					}
					else {
						p->right = n;
						n->parent = p;
					}
				}
			}
		}
		while (q--) {
			int t1, t2;
			cin >> t1 >> t2;
			Node* tmp1 = new Node(); Node* tmp2 = new Node();
			for (size_t i = 0; i < node_list.size(); i++) {
				if (node_list[i]->data == t1)
					tmp1 = node_list[i];
				else if (node_list[i]->data == t2)
					tmp2 = node_list[i];
				if (tmp1->data != -1 && tmp2->data != -1)
					break;
			}

			while (tmp1 != NULL) {
				tmp1->check = true;
				tmp1 = tmp1->parent;
			}

			while (tmp2 != NULL) {
				if (tmp2->check) {
					cout << tmp2->data << "\n";
					break;
				}
				tmp2 = tmp2->parent;
			}

			for (size_t i = 0; i < node_list.size(); i++) {
				if (node_list[i]->data == t1) {
					tmp1 = node_list[i];
					break;
				}
			}

			while (tmp1 != NULL) {
				tmp1->check = false;
				tmp1 = tmp1->parent;
			}
		}

		for (size_t i = 0; i < node_list.size(); i++)
			delete node_list[i];
		node_list.clear();
	}
}