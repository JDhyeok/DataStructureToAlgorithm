#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int N, M, ans = 987654321;
bool visited[51];
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

int calcDist(pair<int, int>, pair<int, int>);

void dfs(int cur, int depth) {
	
	if (depth == M) {
		int tmpAns = 0;

		for (int i = 0; i < houses.size(); i++) {
			int tmp = 987654321;
			for (int j = 0; j < chickens.size(); j++) {
				if (visited[j])
					tmp = min(tmp, calcDist(houses[i], chickens[j]));
			}

			tmpAns += tmp;
		}

		ans = min(ans, tmpAns);
		return;
	}

	if (cur == chickens.size())
		return;

	visited[cur] = true;
	dfs(cur + 1, depth + 1);
	visited[cur] = false;
	dfs(cur + 1, depth);
}

int calcDist(pair<int,int> a, pair<int,int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill_n(visited, 51, false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;

			if (tmp == 1) {
				houses.push_back({ i,j });
			}
			else if (tmp == 2) {
				chickens.push_back({ i,j });
			}
		}
	}

	dfs(0, 0);

	cout << ans << "\n";

	return 0;
}