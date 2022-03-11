#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

#define MAX 501
#define DIR 4


int N, M;
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
bool board[MAX][MAX];

// 2264KB, 32 ms
int BFS(int i, int j) {
	
	int size = 1;
	queue<pair<int, int>> q;
	
	board[i][j] = 0;
	q.push({ i, j });

	while (!q.empty()) {
		int curi = q.front().first;
		int curj = q.front().second;
		q.pop();

		for (int d = 0; d < DIR; d++) {
			int nexti = curi + dir[d][0];
			int nextj = curj + dir[d][1];

			if (nexti < 0 || nextj < 0 || nexti >= N || nextj >= M)
				continue;

			if (board[nexti][nextj] == 1) {
				size++;
				board[nexti][nextj] = 0;
				q.push({ nexti, nextj });
			}
		}
	}

	return size;
}


int tmp_size = 0;

// 13865 KB, 32 ms
void DFS(int i, int j) {
	board[i][j] = 0;
	tmp_size++;
	for (int d = 0; d < DIR; d++) {
		int nexti = i + dir[d][0];
		int nextj = j + dir[d][1];

		if (nexti < 0 || nextj < 0 || nexti >= N || nextj >= M)
			continue;

		if (board[nexti][nextj] == 1)
			DFS(nexti, nextj);
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int pic_cnt = 0;
	int pic_max = 0;

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1) {
				pic_cnt++;
				pic_max = max(pic_max, BFS(i, j));
			}
		}
	}*/

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1) {
				pic_cnt++;
				tmp_size = 0;
				DFS(i, j);
				pic_max = max(pic_max, tmp_size);
			}
		}
	}

	cout << pic_cnt << "\n" << pic_max;

	return 0;
}