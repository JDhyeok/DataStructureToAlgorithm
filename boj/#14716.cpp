#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

#define MAX 251
#define DIR 8

int N, M;
int way[8][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };
bool board[MAX][MAX];

void bfs(pair<int, int> start_point) {
	queue<pair<int, int>> q;

	board[start_point.first][start_point.second] = 0;
	q.push(start_point);

	while (!q.empty()) {
		int curi = q.front().first;
		int curj = q.front().second;
		q.pop();
		
		for (int d = 0; d < DIR; d++) {
			int nexti = curi + way[d][0];
			int nextj = curj + way[d][1];

			// 범위 check
			if (nexti < 0 || nextj < 0 || nexti >= N || nextj >= M)
				continue;

			if (board[nexti][nextj] == 1) {
				board[nexti][nextj] = 0;
				q.push({ nexti, nextj });
			}
		}
	}
	return;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(board[i][j] == 1){
				bfs({ i, j });

				ans++;
			}
		}
	}

	cout << ans << "\n";
	
	return 0;
}