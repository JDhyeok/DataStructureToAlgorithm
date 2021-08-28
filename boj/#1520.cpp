#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<array>
#include<unordered_map>

using namespace std;

int N, M;
int mat[501][501] = { 0, };
int dp[501][501] = { 0, };
long ans = 0;

int WAY[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

bool visited[501][501];

int dfs(int curi , int curj) {
	
	if (curi == N - 1 && curj == M - 1) {
		return 1;
	}

	for (int w = 0; w < 4; w++) {
		int ni = curi + WAY[w][0];
		int nj = curj + WAY[w][1];

		if (ni < 0 || nj < 0 || ni >= N || nj >= M || mat[curi][curj] <= mat[ni][nj])
			continue;

		if (visited[ni][nj]) {
			dp[curi][curj] += dp[ni][nj];
			continue;
		}

		dp[curi][curj] += dfs(ni, nj);
	}
	visited[curi][curj] = true;
	
	return dp[curi][curj];
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mat[i][j];
		}
	}
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = false;


	dfs(0, 0);


	cout << dp[0][0] << "\n";

	return 0;
}
