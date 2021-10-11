#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

#define MAX 101

int M, N, K;
int map[MAX][MAX];
bool visited[MAX][MAX];

int way[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };


int bfs(int si, int sj) {
	int ret = 1;

	queue<pair<int,int>> q;

	q.push({ si, sj });
	visited[si][sj] = true;

	while (!q.empty()) {
		int curi = q.front().first;
		int curj = q.front().second;
		q.pop();

		for (int w = 0; w < 4; w++) {
			int ni = curi + way[w][0];
			int nj = curj + way[w][1];

			if (ni < 0 || nj < 0 || ni >= N || nj >= M || visited[ni][nj] || map[ni][nj])
				continue;

			q.push({ ni, nj });
			visited[ni][nj] = true;
			ret++;
		}
	}

	return ret;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N >> K;


	int si, sj, ei, ej;

	for (int k = 0; k < K; k++) {
		cin >> si >> sj >> ei >> ej;

		for (int i = si; i < ei; i++) 
			for (int j = sj; j < ej; j++) 
				map[i][j] = 1;
	}

	vector<int> ans;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == false && map[i][j] == 0) {
				ans.push_back(bfs(i, j));
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (auto a : ans)
		cout << a << " ";

	return 0;
}
