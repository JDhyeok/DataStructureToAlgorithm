#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int N;
int map[17][17], dp[17][17][3];
vector<pair<int, int>> way = { {0, 1}, {1, 1}, {1, 0} };
bool visited[17][17][3];

int dfs(int i, int j, int curDir) {

	if (visited[i][j][curDir])
		return dp[i][j][curDir];
	// 목적지일 때
	if (i == N - 1 && j == N - 1) {
		dp[i][j][curDir] = 1;
		return 1;
	}

	for (int dir = 0; dir < 3; dir++) {
		if (abs(curDir - dir) > 1) // 방향 안맞을 때
			continue;

		// 파이프 전환
		int ni = i + way[dir].first;
		int nj = j + way[dir].second;

		// 범위 or 벽일 때
		if (ni < 0 || nj < 0 || ni >= N || nj >= N || map[ni][nj] == 1)
			continue;
		if (dir == 1 && (map[ni - 1][nj] == 1 || map[ni][nj - 1] == 1))
			continue;

		// 방향과 함께 다음 파이프로
		dp[i][j][curDir] += dfs(ni, nj, dir);
	}

	// 해당 방향의 파이프라인 방문 완료
	visited[i][j][curDir] = true;
	

	return dp[i][j][curDir];
}

int main() {

	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int d = 0; d < 3; d++)
				visited[i][j][d] = false;




	dfs(0, 1, 0);


	cout << (dp[0][1][0] + dp[0][1][1] + dp[0][1][2]) << "\n";

	return 0;
}
