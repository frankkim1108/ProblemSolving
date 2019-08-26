#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > TaskList;

int main()
{
	std::ios::sync_with_stdio(false);
	
	int T;
	cin >> T;

	while (T--) {

		long long current = 0;
		long long wait = 0;
		long long response = 0;
		int N = 0;
		cin >> N;

		for (int i = 0; i < N; i++) {
			int input;
			int duration;
			pair<int, int> Task;
			cin >> input >> duration;
			
			Task = make_pair(input, duration);
			TaskList.push_back(Task);
		}

		for (int i = 0; i < TaskList.size(); i++)
		{
			if(i == 0 || current < TaskList[i].first)
			current = TaskList[i].first;
			wait += current - TaskList[i].first;
			current += TaskList[i].second;
			response += current - TaskList[i].first;
		}

		cout << wait / N << " " << response / N << "\n";

		TaskList.clear();

	}

	return 0;
}