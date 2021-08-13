#include<iostream>
#include<algorithm>

using namespace std;


int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, table[1000][3], R, G, B;
	int dp[1000][3];

	cin >> N;

	for (int n = 0; n < N; n++) {
		cin >> R >> G >> B;
		table[n][0] = R;
		table[n][1] = G;
		table[n][2] = B;
	}
	dp[0][0] = table[0][0];
	dp[0][1] = table[0][1];
	dp[0][2] = table[0][2];

	for (int i = 1; i < N; i++) {
		dp[i][0] = min(table[i][0] + dp[i - 1][1], table[i][0] + dp[i - 1][2]);
		dp[i][1] = min(table[i][1] + dp[i - 1][0], table[i][1] + dp[i - 1][2]);
		dp[i][2] = min(table[i][2] + dp[i - 1][0], table[i][2] + dp[i - 1][1]);
	}
	int ans;

	ans = min(dp[N-1][0],min(dp[N - 1][1], dp[N - 1][2]));

	cout << ans << "\n";

	return 0;
}