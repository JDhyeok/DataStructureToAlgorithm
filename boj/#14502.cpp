#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

# define NEW_WALL 3

int N, M;
int map[9][9];
int WAY[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
bool visited[9][9];
vector<pair<int, int>> virus;

void initvisited() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = false;
}

// BFS 풀이 92ms
int count_vius() {

	int cnt = 0;

	queue<pair<int, int>> q;

	for (int i = 0; i < virus.size(); i++)
		q.push({ virus[i].first, virus[i].second });

	while (!q.empty()) {
		int curi = q.front().first;
		int curj = q.front().second;
		q.pop();

		for (int w = 0; w < 4; w++) {
			int ni = curi + WAY[w][0];
			int nj = curj + WAY[w][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= M || map[ni][nj] || visited[ni][nj])
				continue;

			cnt++;
			visited[ni][nj] = true;
			q.push({ ni, nj });
		}
	}

	return cnt;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	vector<pair<int, int>> point;
	

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				point.push_back({ i, j });

			if (map[i][j] == 2)
				virus.push_back({ i,j });

			visited[i][j] = false;
		}
	}

	int maxSafe = 0;

	for (int i = 0; i < point.size() - 2; i++) {
		for (int j = i + 1; j < point.size() - 1; j++) {
			for (int k = i + 2; k < point.size(); k++) {
				// 방문 초기화
				initvisited();

				// 벽 세우기
				map[point[i].first][point[i].second] = 1;
				map[point[j].first][point[j].second] = 1;
				map[point[k].first][point[k].second] = 1;


				int infected = count_vius();

				maxSafe = max(maxSafe, int(point.size() - infected - NEW_WALL));

				// 벽 치우기
				map[point[i].first][point[i].second] = 0;
				map[point[j].first][point[j].second] = 0;
				map[point[k].first][point[k].second] = 0;

			}
		}
	}

	cout << maxSafe << "\n";

	return 0;
}


// DFS 풀이  60ms
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

# define NEW_WALL 3

int virus_num;

void dfs(int i, int j) {
	
	for (int w = 0; w < 4; w++) {
		int ni = i + WAY[w][0];
		int nj = j + WAY[w][1];


		if (ni < 0 || nj < 0 || ni >= N || nj >= M || map[ni][nj] || visited[ni][nj])
			continue;

		virus_num++;
		visited[ni][nj] = true;
		dfs(ni, nj);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	vector<pair<int, int>> point;
	

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				point.push_back({ i, j });

			if (map[i][j] == 2)
				virus.push_back({ i,j });

			visited[i][j] = false;
		}
	}

	int maxSafe = 0;

	for (int i = 0; i < point.size() - 2; i++) {
		for (int j = i + 1; j < point.size() - 1; j++) {
			for (int k = i + 2; k < point.size(); k++) {
				// 방문 초기화
				initvisited();

				// 벽 세우기
				map[point[i].first][point[i].second] = 1;
				map[point[j].first][point[j].second] = 1;
				map[point[k].first][point[k].second] = 1;

				//dfs
				virus_num = 0;

				for (int i = 0; i < virus.size(); i++)
					dfs(virus[i].first, virus[i].second);

				maxSafe = max(maxSafe, int(point.size() - virus_num - NEW_WALL));

				// 벽 치우기
				map[point[i].first][point[i].second] = 0;
				map[point[j].first][point[j].second] = 0;
				map[point[k].first][point[k].second] = 0;

			}
		}
	}

	cout << maxSafe << "\n";

	return 0;
}
