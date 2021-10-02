#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

#define MAX 101

int N, M, hour = 0, last_cheese = 0;
int cheese[MAX][MAX], cnt[MAX][MAX];
int way[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
bool visited[MAX][MAX];

void init();
void solve();
void bfs(queue<pair<int, int>>&, int, int);

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cnt[i][j] = 0;
			visited[i][j] = false;
		}
	}


}

void solve() {
	queue<pair<int, int>> q;

	while (1) {
		init();
		bfs(q, 0, 0);

		// 치즈가 없다면 끝
		if (q.empty())
			return;

		// 마지막에는 모든 치즈가 없어지기 때문에 마지막 없어지는 치즈 저장? 왜 없누
		last_cheese = q.size();

		while (!q.empty()) {
			cheese[q.front().first][q.front().second] = 0;
			q.pop();
		}

		/*cout << endl << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << cheese[i][j] << " ";
			}
			cout << endl;
		}*/

		// 시간 보내기
		hour++;

	}
}

void bfs(queue<pair<int, int>>& q, int i, int j) {
	queue<pair<int, int>> tq;

	tq.push({ i,j });

	while (!tq.empty()) {
		int curi = tq.front().first;
		int curj = tq.front().second;
		tq.pop();

		for (int w = 0; w < 4; w++) {
			int ni = curi + way[w][0];
			int nj = curj + way[w][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= M || visited[ni][nj])
				continue;

			// cheese 인지 확인하고 2번 이상 접근됐다면 q에 삽입
			if (cheese[ni][nj] == 1) {
				cnt[ni][nj]++;
				if (cnt[ni][nj] > 1)
					q.push({ ni, nj });
				continue;
			}

			visited[ni][nj] = true;
			tq.push({ ni, nj });
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> cheese[i][j];

	solve();
	
	cout << hour << "\n";

	return 0;
}