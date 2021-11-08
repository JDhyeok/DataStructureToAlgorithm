/*#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

int N, K;
int mask[51], ans = 0;

int countOne(int n) {
	int ret = 0;
	
	for (int i = 0; i < 26; i++) {
		if ((n & 1) > 0)
			ret++;
		n = n >> 1;
	}
	return ret;
}

void dfs(int all_mask, int k) {
	
	if (k > K) {
		return;
	}

	int n = countOne(all_mask);

	if (n == k) {
		// 단어 셀 수 있으면 세기

	}

	for (int i = 0; i < 26; i++) {

	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> K;

	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		// masking
		for (int j = 0; j < tmp.size(); j++) {
			mask[i] |= 1 << (tmp[i] - 'a');
		}
	}

	int all_mask = 2147483647;
	for (int i = 0; i < N; i++) {
		all_mask &= mask[i];
	}
	int n = countOne(all_mask);

	dfs(all_mask, n);

	return 0;
}*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

struct Point {
	int i, j;
	Point(int i, int j) : i(i), j(j) {}
};

int N, M;
int way[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
char board[51][51];
bool visited[51][51];
vector<Point> continent;

void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			visited[i][j] = false;

}

int bfs(Point strt) {
	init();

	int ret = 0;
	queue<pair<Point, int>> q;

	visited[strt.i][strt.j] = true;
	q.push({ strt, 0 });

	while (!q.empty()) {
		Point cur = q.front().first;
		int dist = q.front().second;
		q.pop();

		for (int w = 0; w < 4; w++) {
			int ni = cur.i + way[w][0];
			int nj = cur.j + way[w][1];

			// 범위
			if (ni < 0 || nj < 0 || ni >= N || nj >= M)
				continue;

			// 방문 여부, 바다
			if (visited[ni][nj] || board[ni][nj] == 'W')
				continue;

			visited[ni][nj] = true;
			q.push({ Point(ni, nj), dist + 1 });
			ret = max(ret, dist + 1);
		}
	}

	return ret;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'L')
				continent.push_back(Point(i, j));
		}
	}

	int ans = 0;

	for (int i = 0; i < continent.size(); i++) {
		ans = max(ans, bfs(continent[i]));
	}

	cout << ans;

	return 0;
}