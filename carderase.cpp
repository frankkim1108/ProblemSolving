#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

class Dist {
public:
	Dist() {}
	Dist(pair<int, int> card1, pair<int, int> card2) {
		this->card1 = card1;
		this->card2 = card2;
		this->distant = (card1.first - card2.first)*(card1.first - card2.first)
			+ (card1.second - card2.second)*(card1.second - card2.second);
	}
	pair<int, int> card1;
	pair<int, int> card2;
	int distant;
};

bool compare(Dist d1, Dist d2) {
	if (d1.distant == d2.distant) {
		if (d1.card1.first + d1.card2.first == d2.card1.first + d2.card2.first)
			return d1.card1.second + d1.card2.second < d2.card1.second + d2.card2.second;
		else return d1.card1.first + d1.card2.first < d2.card1.first + d2.card2.first;
	}
	return d1.distant < d2.distant;
}

int main() {
	std::ios::sync_with_stdio(false);
	int T, N, M;
	cin >> T;

	while (T--) {
		cin >> N >> M;
		vector<Dist> dist[26];
		vector<pair<int, int> > cards[26];

		for (int i = 0; i < M; i++) {
			char shape;
			int x, y;
			cin >> shape >> x >> y;
			cards[shape - 65].push_back(make_pair(y, x));
		}


		for (int k = 0; k < 26; k++) {
			if (!cards[k].empty()) {
				sort(cards[k].begin(), cards[k].end());

				for (int i = 0; i < cards[k].size() - 1; i++) {
					for (int j = i + 1; j < cards[k].size(); j++) {
						dist[k].push_back(Dist(cards[k][i], cards[k][j]));
					}
				}
			}
		}



		for (int i = 0; i < 26; i++) {
			if (!dist[i].empty()) {
				sort(dist[i].begin(), dist[i].end(), compare);

				for (int j = 0; j < dist[i].size(); j++) {
					if (dist[i][j].distant != -1) {
						char shape = i + 65;
						cout << shape << ' '
							<< dist[i][j].card1.second << ' ' << dist[i][j].card1.first << ' '
							<< dist[i][j].card2.second << ' ' << dist[i][j].card2.first << '\n';
						for (int k = j; k < dist[i].size(); k++) {
							if (dist[i][k].card1 == dist[i][j].card1 || dist[i][k].card1 == dist[i][j].card2
								|| dist[i][k].card2 == dist[i][j].card1 || dist[i][k].card2 == dist[i][j].card2) {
								dist[i][k].distant = -1;
							}
						}
					}
				}
			}
		}


	}
}