#include<iostream>
#include<vector>
#include<stack>
#include<utility>
#include<queue>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	vector<pair<pair<int, int>, int> > tower;
	

	while (T--) {
		int N = 0;
		cin >> N;
	stack<pair<pair<int, int>, int> > city;
	stack<pair<pair<int, int>, int> > event;
		for (int i = 1; i <= N; i++) {
			int height = 0;
			int eventnum = 0;
			cin >> height;
			pair<pair<int, int>, int> building;
			building = make_pair(make_pair(i, height), eventnum);
			tower.push_back(building);
			city.push(tower[i-1]);
		}
		while (!city.empty()){	
			pair<pair<int, int>, int> temp;
			temp = city.top();
			while (!event.empty()) {
				if (temp.first.second >= event.top().first.second)
				{
					tower[event.top().first.first-1].second = city.size();
					event.pop();
				}
				else {
					break;
				}
			}
				event.push(temp);
				city.pop();
			
		}
		
		for (int i = 1; i <= N; i++){
			cout << tower[i-1].second << " ";
		}
		cout << "\n";
		tower.clear();
		
	}

	return 0;
}