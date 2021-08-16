#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, M;
int table[100][100] = { 0, };

int check(int, int);

int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int user1, user2;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> user1 >> user2;
		table[user1 - 1][user2 - 1] = 1;
		table[user2 - 1][user1 - 1] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (table[i][j] == 0) {
				int tmp = check(i, j);
				table[i][j] = tmp;
				table[j][i] = tmp;
			}
		}
	}

	int MIN = 987654321, ans = 0;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			sum += table[i][j];
		}
		if (sum < MIN) {
			MIN = sum;
			ans = i;
		}
	}
	cout << ans + 1 << "\n";

	return 0;
}

int check(int init, int dest) {
	if (init == dest)
		return 0;

	int visited[100] = { 0, };
	queue<int> q;
	q.push(dest);
	visited[dest] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < N; i++) {
			if (i == init && table[cur][i] == 1)
				return visited[cur];

			if (!visited[i] && table[cur][i] == 1) {
				q.push(i);
				visited[i] = visited[cur] + 1;
			}
		}
	}

	return 0;
}