#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;



int main()
{
	int T;
	cin >> T;

	while (T--) {
		int M;
		priority_queue<int> smaller;
		priority_queue<int, vector<int>, greater<int> > bigger;
		cin >> M;

		int number;
		cin >> number;
		smaller.push(number);
		cout << smaller.top() << " ";
		for (int i = 1; i < M; i++) {
			if (smaller.size() == bigger.size()) {
				int num;
				cin >> num;
				smaller.push(num);
			}
			else {
				int num;
				cin >> num;
				bigger.push(num);
			}
			if (smaller.top() > bigger.top()) {
				int temp = smaller.top();
				int temp1 = bigger.top();
				smaller.pop();
				bigger.pop();
				smaller.push(temp1);
				bigger.push(temp);
			}
			cout << smaller.top() << " ";
		}

		cout << endl;

	}
	return 0;

}