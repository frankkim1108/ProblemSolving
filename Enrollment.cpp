#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector <pair<string, unsigned int> > List;
		map<string, set<unsigned int> > list;
		set<unsigned int> Temp;
		set<unsigned int> Dup;
		for (int i = 0; i < N; i++) {
			int Sid; string name;
			cin >> Sid >> name;
			List.push_back(make_pair(name, Sid));
		}

		for (unsigned int i = 0; i < List.size(); i++) {
			if (list.count(List[i].first) == 0) {
				Temp.insert(List[i].second);
				list.insert(make_pair(List[i].first, Temp));
				Temp.clear();
			}
			else {
				if (list[List[i].first].count(List[i].second) == 0)
					list[List[i].first].insert(List[i].second);
				else
					Dup.insert(List[i].second);
			}
		}

		int H = 0, C = 0;

		map <string, set<unsigned int> >::iterator iter;
		for (iter = list.begin(); iter != list.end(); iter++) {
			if (iter->second.size() > 1)
				H = H + iter->second.size();
		}

		C = Dup.size();

		cout << C << " " << H << "\n";


	}
}