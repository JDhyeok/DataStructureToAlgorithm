#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

int N, K;
bool visited[9];
vector<int> A;
vector<vector<int>> comb;

void dfs(int depth, vector<int> tmp) {
	if (depth == N) {
		comb.push_back(tmp);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i])
			continue;

		tmp.push_back(A[i]);
		visited[i] = true;

		dfs(depth + 1, tmp);

		tmp.pop_back();
		visited[i] = false;
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		A.push_back(tmp);
	}

	vector<int> t;

	fill_n(visited, 9, false);
	dfs(0, t);
	

	int ans = comb.size();


	for (int i = 0; i < comb.size(); i++) {
		int sum = 0;
		for (int j = 0; j < comb[i].size(); j++) {
			sum += comb[i][j];

			if (sum - (j + 1) * K < 0) {
				ans--;
				break;
			}
		}
	}
	cout << ans;

	return 0;
}
