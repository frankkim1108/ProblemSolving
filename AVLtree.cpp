#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;
#define _max(x,y) ((x > y) ? x : y)

// class Node 정의
class Node
{
public:
	int height;
	int key;
	string value;
	Node *parent, *left, *right;
	Node() {               // 생성자1
		key = height = 0;
		value = "";
		parent = left = right = NULL;
	};
	Node(int key, string value) {   // 생성자2
		this->key = key;
		this->value = value;
		parent = left = right = NULL;
		height = 0;
	};
};

// class AVLTree (AVL 트리) 정의
class AVLTree
{
public:
	Node *root;
	int n;
	AVLTree() {      // 생성자
		this->root = NULL;
		n = 0;
	};
	Node* find(int key, Node* v);
	Node* insert(int key, string value);

	int height(Node* v);
	void setHeight(Node* v);
	bool isBalanced(Node *v);
	Node* tallGrandChild(Node* v);
	Node* restructure(Node* v);
	void rebalance(Node* v);
	bool isExternal(Node* v);

	int size();
	bool empty();
};

// AVL 트리의 size 반환
int AVLTree::size() {
	return n;
}

// AVL 트리의 empty 여부 반환
bool AVLTree::empty() {
	return (n == 0);
}

// 노드v가 leaf 노드인지 확인
bool AVLTree::isExternal(Node* v) {
	return (v->left == NULL && v->right == NULL);
}

// 노드 v의 높이 반환
int AVLTree::height(Node* v) {
	if (v == NULL)
		return -1;
	else
		return (isExternal(v)) ? 0 : v->height;
}

// 노드 v의 높이 계산
void AVLTree::setHeight(Node* v) {
	int hl = height(v->left);   // height of left child
	int hr = height(v->right);   // height of right child
	v->height = 1 + _max(hl, hr);
}

//  노드 v에 대해 균형 여부 확인
bool AVLTree::isBalanced(Node *v) {
	int bal = height(v->left) - height(v->right);
	return ((-1 <= bal) && (bal <= 1));
}

// 최초의 불균형 노드 z에 대해, height가 더 큰, z의 grandchld 탐색
Node* AVLTree::tallGrandChild(Node* z) {
	Node* zl = z->left;
	Node* zr = z->right;
	if (height(zl) >= height(zr)) {
		if (height(zl->left) >= height(zl->right))   // 자식과 같은 방향의 손자를 우선적으로 선택
			return zl->left;
		else
			return zl->right;
	}
	else {
		if (height(zr->right) >= height(zr->left))   // 자식과 같은 방향의 손자를 우선적으로 선택
			return zr->right;
		else
			return zr->left;
	}
}

Node* RR(Node* z, Node* y) {
	Node* tmp = y->left;
	z->right = tmp;
	if (tmp != NULL)
		tmp->parent = z;
	y->left = z;
	if (z->parent != NULL) {
		if (z->parent->left == z) z->parent->left = y;
		else z->parent->right = y;
	}
	y->parent = z->parent;
	z->parent = y;
	return y;
}

Node* LL(Node* z, Node* y) {
	Node* tmp = y->right;
	z->left = tmp;
	if (tmp != NULL)
		tmp->parent = z;
	y->right = z;
	if (z->parent != NULL) {
		if (z->parent->left == z) z->parent->left = y;
		else z->parent->right = y;
	}
	y->parent = z->parent;
	z->parent = y;
	return y;
}

/****************************************************************************************************************************************///학생이 구현. 

Node* AVLTree::restructure(Node* x) {
	Node* y = x->parent;
	Node* z = y->parent;
	if (z->left == y) {
		if (y->left == x) {
			return LL(z, y);
		}
		else {
			y = RR(y, x);
			return LL(z, y);
		}
	}
	else {
		if (y->left == x) {
			y = LL(y, x);
			return RR(z, y);
		}
		else {
			return RR(z, y);
		}
	}
}

/*****************************************************************************************************************************************///학생이 구현




																								   // 불균형 노드가 있으면, restructuring
void AVLTree::rebalance(Node* v) {
	Node *z = v;
	while (z->parent != NULL) {
		z = z->parent;
		setHeight(z);
		if (!isBalanced(z)) {
			Node* x = tallGrandChild(z);
			z = restructure(x);      // -------------------> restructure() 를 직접 구현해야합니다.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			setHeight(z->left);
			setHeight(z->right);
			setHeight(z);
		}
	}
	root = z;
}



//key가 삽입될 위치 반환
Node* AVLTree::find(int key, Node* v) {
	Node* leafNode;
	leafNode = NULL;

	while (v != NULL) {
		leafNode = v;
		if (key < v->key)
			v = v->left;
		else if (key > v->key)
			v = v->right;
		else
			return v;
	}

	// leaf까지 도달한 경우, leaf노드를 반환한다. 
	return leafNode;
}


//노드 삽입
Node* AVLTree::insert(int key, string value) {
	Node *curLeafNode = find(key, root);
	Node *newNode = new Node(key, value);
	Node *insertNode = new Node();

	if (key < curLeafNode->key)   // 삽입하려는 key가 현재 leaf노드의 key보다 작은 경우
	{
		curLeafNode->left = newNode;
	}
	else    // 삽입하려는 key가  현재 leaf노드의 key보다 큰 경우
	{
		curLeafNode->right = newNode;
	}
	newNode->parent = curLeafNode;
	n++;

	// restructure 및 height 갱신
	setHeight(newNode);
	rebalance(newNode);


	// 삽입된 AVL tree의 노드의 height 출력
	insertNode = find(key, root);
	cout << insertNode->value << " " << insertNode->height << endl;
	return insertNode;
}


int main()
{
	ios::sync_with_stdio(false);
	int t, key;
	string instruct;
	AVLTree T;

	cin >> t;
	while (t--) {
		Node* tempNode;
		cin >> instruct;
		if (instruct == "find") {

			cin >> key;

			tempNode = T.find(key, T.root);
			if (tempNode->key == key)
				cout << tempNode->value << " " << tempNode->height << endl;
			else cout << -1 << endl;

		}

		else if (instruct == "insert") {
			cin >> key >> instruct;
			if (T.empty()) {
				T.root = new Node(key, instruct);
				T.n++;
				cout << T.root->value << " " << T.root->height << endl;
			}
			else
				T.insert(key, instruct);
		}
	}
	return 0;
}