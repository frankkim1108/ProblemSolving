#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int Populate(vector<vector<int> > M, int H, queue< pair<int, int> > Q) {
	int R = 0;
	while (!Q.empty())
	{
		bool infection = false;
		int L = Q.size();
		for (int i = 0; i < L; i++) {
			pair<int, int> temp;
			pair<int, int> a = Q.front();
			Q.pop();
			if (M[a.first + 1][a.second] != 1) {
				M[a.first + 1][a.second] = 1;
				temp = make_pair(a.first + 1, a.second);
				Q.push(temp);
				H--;
				infection = true;
			}
			if (M[a.first - 1][a.second] != 1) {
				M[a.first - 1][a.second] = 1;
				temp = make_pair(a.first - 1, a.second);
				Q.push(temp);
				H--;
				infection = true;
			}
			if (M[a.first][a.second + 1] != 1) {
				M[a.first][a.second + 1] = 1;
				temp = make_pair(a.first, a.second + 1);
				Q.push(temp);
				H--;
				infection = true;
			}
			if (M[a.first][a.second - 1] != 1) {
				M[a.first][a.second - 1] = 1;
				temp = make_pair(a.first, a.second - 1);
				Q.push(temp);
				H--;
				infection = true;
			}

		}
		if (infection == true)
			R++;

	}
	if (H != 0)
		R = -1;
	return R;

}

int main()
{
	std::ios::sync_with_stdio(false);

	int H;
	int T;
	cin >> T;

	while (T--) {
		int N = 0, M = 0;
		cin >> N >> M;
		int count = 0;
		vector< vector<int> > Grid(N + 2, vector<int>(N + 2));
		queue <pair<int, int> > pos;
		for (int i = 0; i < N + 2; i++)
		{
			for (int j = 0; j < N + 2; j++)
			{
				if (i == 0 || j == 0)
				{
					Grid[i][j] = 1;
				}
				if (i == N + 1 || j == N + 1)
				{
					Grid[i][j] = 1;
				}
			}
		}
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
			{
				cin >> Grid[i][j];
			}
		}

		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++) {
				if (Grid[i][j] == 1)
					count++;
			}
		}
		H = N * N - (count + M);

		for (int i = 0; i < M; i++)
		{
			int x = 0, y = 0;
			cin >> x >> y;
			Grid[N - y][x + 1] = 1;
			pair<int, int> position = make_pair(N - y, x + 1);
			pos.push(position);
		}
		cout << Populate(Grid, H, pos) << "\n";


	}
}