#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

#define MAX 100001

int N, K, way = 1;
int dp[MAX];

void bfs() {



	queue<pair<int, int>> q;

	q.push({ N, 0 });
	dp[N] = 0;

	if (N == K)
		return;

	while (!q.empty()) {
		int cur = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (cur == K && dp[K] == cost)
			way++;

		if (dp[cur] < cost)
			continue;


		dp[cur] = cost;

		if (cur + 1 < MAX) {
			q.push({ cur + 1, dp[cur] + 1 });
		}

		if (cur - 1 >= 0) {
			q.push({ cur - 1, dp[cur] + 1 });
		}

		if (cur * 2 < MAX) {
			q.push({ cur * 2, dp[cur] + 1 });
		}

	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	fill_n(dp, MAX, 999999999);
	bfs();


	cout << dp[K] << "\n" << way;

	return 0;
}