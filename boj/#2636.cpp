#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

#define MAX 101

int N, M, cheeseNum = 0;
int board[MAX][MAX];
int way[4][2] = { {0, 1},{1, 0},{-1, 0},{0, -1} };
vector<pair<int, int>> edges;
bool visited[MAX][MAX];

void init() {
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			visited[i][j] = false;
	
}

void bfs(pair<int,int> cur) {
	
	int cnt = 0;
	queue<pair<int, int>> q;

	init();
	
	visited[cur.first][cur.second] = true;
	q.push({ cur.first , cur.second });

	while (!q.empty()) {
		int curi = q.front().first;
		int curj = q.front().second;
		q.pop();

		for (int w = 0; w < 4; w++) {
			int ni = curi + way[w][0];
			int nj = curj + way[w][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= M || board[ni][nj] > 1 || visited[ni][nj])
				continue;

			if (board[ni][nj] == 1) {
				board[ni][nj] = 2;
				cnt++;
				continue;
			}

			visited[ni][nj] = true;
			q.push({ ni, nj });
		}
	}

	cheeseNum -= cnt;
}

void remover() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 2)
				board[i][j] = 0;
		}
	}
}

void solver() {
	bfs({ 0 ,0 });
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j])
				cheeseNum++;
			if (i == 0 || j == 0 || i == N - 1 || j == M - 1)
				edges.push_back({ i, j });
		}
	}

	int cnt = 0, prev = cheeseNum;
	while (cheeseNum) {
		prev = cheeseNum;
		cnt++;
		solver();
		remover();
	}

	cout << cnt << "\n" << prev;

	return 0;
}
