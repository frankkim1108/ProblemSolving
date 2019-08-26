#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int hair[1000001];


int bin_search(int data, int size) {
	int High = size;
	int Low = 1;
	int Mid = (High + Low) / 2;
	while (High != Mid) {
		if (hair[Mid] == data)
			return Mid;
		else if (hair[Mid] > data) {
			High = Mid;
			Mid = (High + Low) / 2;
		}
		else if (hair[Mid] < data) {
			Low = Mid;
			Mid = (High + Low) / 2;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		int N = 0;
		int M = 0;
		cin >> N >> M;

		for (int i = 1; i <= N; i++) {
			int length = 0;
			cin >> length;
			hair[i] = length;
		}

		for (int i = 0; i < M; i++) {
			int question = 0;
			cin >> question;
			cout << bin_search(question, N) << "\n";
		}

		;
	}

	return 0;
}