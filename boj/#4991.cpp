#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<unordered_map>

using namespace std;

#define INF 987654321

int N, M, ans = INF;
vector<string> map;
vector<pair<int, int>> dust;

int WAY[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int bfs(pair<int,int> start, pair<int,int> dest) {
	int visited[20][20] = { 0, };
	queue<pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = 1;

	while (!q.empty()) {
		int curi = q.front().first;
		int curj = q.front().second;
		q.pop();

		for (int w = 0; w < 4; w++) {
			int ni = curi + WAY[w][0];
			int nj = curj + WAY[w][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= M || visited[ni][nj] || map[ni][nj] == 'x')
				continue;

			if (dest.first == ni && dest.second == nj)
				return visited[curi][curj];

			q.push(make_pair(ni, nj));
			visited[ni][nj] = visited[curi][curj] + 1;

		}
	}
	return -1;
}

void dfs(int start, bool visit[20], int vertex[400][400], int sum) {
	visit[start] = true;

	// base case
	bool flag = true;
	for (int i = 1; i < dust.size(); i++) {
		if (visit[i] == false)
			flag = false;
	}

	if (flag == true) {
		ans = min(ans, sum);
		return;
	}

	for (int i = 1; i < dust.size(); i++) {
		if (!visit[i]) {

			dfs(i, visit, vertex, sum + vertex[start][i]);

			visit[i] = false;
		}
	}
	return;
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int vertex[400][400];
	
	string tmp;

	while (1) {

		cin >> M >> N;
		if (N == 0 && M == 0)
			break;

		// init
		map.clear();
		tmp.clear();
		dust.clear();
		ans = INF;

		// 맵 입력
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			map.push_back(tmp);
		}

		// 시작점 dust에 0으로 push
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 'o')
					dust.push_back(make_pair(i,j));
			}
		}

		// 쓰레기 dust에 0으로 push
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == '*')
					dust.push_back(make_pair(i, j));
			}
		}

		bool flag = false;

		for (int i = 0; i < 400; i++)
			for (int j = 0; j < 400; j++)
				vertex[i][j] = INF;
			
		// 각 노드에서 노드로 가는 모든 경로의 최단거리를 bfs로 구함
		for (int i = 0; i < dust.size() - 1; i++) {
			for (int j = i + 1; j < dust.size(); j++) {
				if (vertex[i][j] == INF) {
					vertex[i][j] = bfs(dust[i], dust[j]);
					vertex[j][i] = vertex[i][j];
				}
				if (vertex[i][j] == -1) {
					flag = true;
					break;
				}
			}
		}
		// 못 치우는 dust 있을 시
		if (flag) {
			cout << -1 << "\n";
			continue;
		}

		/*for (int i = 0; i < dust.size(); i++) {
			for (int j = 0; j < dust.size(); j++) {
				cout << vertex[i][j] << " ";
			}
			cout << endl;
		}*/

		// 시작점 0 부터 모든 정점을 방문하는 최단 경로 구하기
		bool visit[20] = {false,};
		dfs(0, visit, vertex, 0);
		cout << ans << "\n";


	}
	

	return 0;
}
