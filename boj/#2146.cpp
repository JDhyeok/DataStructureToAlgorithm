#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

#define INF 987654321
#define MAX 101

struct Point {
	int i, j;
	Point(int i, int j) :i(i), j(j) {}
};

short board[MAX][MAX];\
bool visited[MAX][MAX];
int N, island_cnt = 2, ans = INF;
int way[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
vector<vector<Point>> island;

bool isConnnect2Sea(int i, int j) {
	for (int w = 0; w < 4; w++) {
		int ni = i + way[w][0];
		int nj = j + way[w][1];

		if (ni < 0 || nj < 0 || ni >= N || nj >= N)
			continue;

		if (board[ni][nj] == 0)
			return true;
	}
	return false;
}

void bfs(int i, int j) {

	vector<Point> ret;
	queue<Point> q;

	board[i][j] = island_cnt;
	if (isConnnect2Sea(i, j))
		ret.push_back(Point(i, j));
	q.push({ i, j });

	while (!q.empty()) {
		Point cur = q.front();
		q.pop();

		for (int w = 0; w < 4; w++) {
			int ni = cur.i + way[w][0];
			int nj = cur.j + way[w][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= N || board[ni][nj] == 0 || board[ni][nj] == island_cnt)
				continue;

			board[ni][nj] = island_cnt;

			// 4방향 막혔을 때만 추가
			if (isConnnect2Sea(ni, nj))
				ret.push_back(Point(ni, nj));

			q.push(Point(ni, nj));
		}
	}
	// 섬 이름 변경
	island_cnt++;
	island.push_back(ret);
}

void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visited[i][j] = false;
}

int dist(Point strt) {
	int cur_island = board[strt.i][strt.j];

	init();

	queue<pair<Point,int>> q;
	visited[strt.i][strt.j] = true;
	q.push({ strt, 0 });

	while (!q.empty()) {
		Point cur = q.front().first;
		int dist = q.front().second;
		q.pop();

		for (int w = 0; w < 4; w++) {
			int ni = cur.i + way[w][0];
			int nj = cur.j + way[w][1];

			// 범위 벗어나거나 같은 섬일경우 pass
			if (ni < 0 || nj < 0 || ni >= N || nj >= N || board[ni][nj] == cur_island || visited[ni][nj] == true)
				continue;

			// 내 섬이 아니고 바다가 아닌 경우 최단거리 이므로 거리 반환
			if (board[ni][nj] != 0 && board[ni][nj] != cur_island) {
				return dist;
			}

			visited[ni][nj] = true;
			q.push({ Point(ni, nj), dist + 1 });
		}
	}
	return INF;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	// 각 섬 번호 다르게하기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1)
				bfs(i, j);
		}
	}

	// 각 섬 끝의 번호에서 가장 짧은 거리들 구하기
	for (int i = 0; i < island.size() - 1; i++) {
		for (int j = 0; j < island[i].size(); j++) {
			ans = min(ans, dist(island[i][j]));
		}
	}

	cout << ans;

	return 0;
}
