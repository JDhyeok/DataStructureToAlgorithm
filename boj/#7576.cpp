#include<iostream>
#include<queue>
#include<string>
#include<math.h>
#include<time.h>
#include<algorithm>

using namespace std;

int board[1001][1001];
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
queue<pair<int, int>> riped_tomato;

int check_all_riped(int board[][1001], int N, int M) {
	int ret = -1;
	for (int i = 0;i < N;i++) {
		for (int j = 0; j < M;j++) {
			ret = max(ret, board[i][j]);
			if (board[i][j] == 0)
				return 0;
		}
	}
	return ret;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 0;
	int N, M, tmp;
	cin >> M >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> tmp;
			board[i][j] = tmp;
			if (tmp == 1) {
				riped_tomato.push({ i, j });
			}
		}
	}
	
	while (!riped_tomato.empty()) {
		int cur_i = riped_tomato.front().first;
		int cur_j = riped_tomato.front().second;
		riped_tomato.pop();

		
		for (int d = 0;d < 4; d++) {
			int next_i = cur_i + dir[d][0];
			int next_j = cur_j + dir[d][1];

			if (next_i < 0 || next_j < 0 || next_i >= N || next_j >= M || board[next_i][next_j] != 0)
				continue;

			board[next_i][next_j] = board[cur_i][cur_j] + 1;
			riped_tomato.push({ next_i, next_j });
		}
		ans++;
	}


	cout << check_all_riped(board, N, M) - 1;

	return 0;
}