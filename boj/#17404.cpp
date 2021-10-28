#include<iostream>
#include<vector>

using namespace std;

#define INF 987654321

int N;
int cost[1001][3], dp[1001][3];

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];

	int ans = INF;

	for (int fix = 0; fix < 3; fix++) {
		dp[1][fix] = INF;
		dp[1][(fix + 1) % 3] = dp[0][fix] + cost[1][(fix + 1) % 3];
		dp[1][(fix + 2) % 3] = dp[0][fix] + cost[1][(fix + 2) % 3];

		for (int i = 2; i < N; i++) {
			dp[i][0] = min(dp[i - 1][1] + cost[i][0], dp[i - 1][2] + cost[i][0]);
			dp[i][1] = min(dp[i - 1][0] + cost[i][1], dp[i - 1][2] + cost[i][1]);
			dp[i][2] = min(dp[i - 1][0] + cost[i][2], dp[i - 1][1] + cost[i][2]);
		}

		for (int i = 0; i < 3; i++) {
			if (i == fix)
				continue;
			ans = min(ans, dp[N - 1][i]);
		}
	}

	cout << ans;

	return 0;
}
