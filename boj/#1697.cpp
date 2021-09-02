#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int N, K;
int dp[1000000];


void bfs() {

	queue<pair<int,int>> q;
	q.push({ N, 0 });

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (dp[cur] < cnt || cur < 0)
			continue;

		dp[cur] = cnt;

		if (cur == K)
			return;

		q.push({ cur * 2, cnt + 1});
		q.push({ cur - 1, cnt + 1 });
		q.push({ cur + 1, cnt + 1 });

	}
}


int main() {

	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	cin >> N >> K;
	
	fill_n(dp, 100001, 987654321);


	
	//dfs(N, 0);
	bfs();

	cout << dp[K] << "\n";

	return 0;
}
