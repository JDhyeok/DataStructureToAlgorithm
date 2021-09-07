#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

#define INF 987654321

int N, M;
char map[1001][1001];
int visited[1001][1001][2];


struct Point {
	int i;
	int j;
	bool crash;

	Point(int i, int j, bool crash) : i(i), j(j), crash(crash) {}
};

int WAY[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

int bfs() {
	queue<Point> q;

	q.push(Point(0, 0, true));

	int curi, curj, curCrash;
	int ni, nj, nCrash;

	while (!q.empty()) {
		curi = q.front().i;
		curj = q.front().j;
		curCrash = q.front().crash;
		q.pop();

		if (curi == N - 1 && curj == M - 1)
			return visited[curi][curj][curCrash];

		for (int w = 0; w < 4; w++) {
			ni = curi + WAY[w][0];
			nj = curj + WAY[w][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= M )
				continue;
			

			if (map[ni][nj] == '1') {
				if (curCrash) {
					visited[ni][nj][0] = visited[curi][curj][curCrash] + 1;
					q.push(Point(ni, nj, false));
					continue;
				}
			}
			else {
				if (visited[ni][nj][curCrash] == 0) {
					visited[ni][nj][curCrash] = visited[curi][curj][curCrash] + 1;
					q.push(Point(ni, nj, curCrash));
				}
			}
		}

	}
	return -1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j][0] = 0;
			visited[i][j][1] = 0;
		}
	}
	visited[0][0][0] = 1;
	visited[0][0][1] = 1;
	cout << bfs() << "\n";

	
	return 0;
}
