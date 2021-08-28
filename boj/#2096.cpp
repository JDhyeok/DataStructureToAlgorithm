#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<array>
#include<unordered_map>

using namespace std;

#define INF 100000

int dp[INF][3];

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	short mat[INF][3];

	int MIN = 987654321, MAX = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> mat[i][j];
		}
	}
	dp[0][0] = dp[0][0] = mat[0][0];
	dp[0][1] = dp[0][1] = mat[0][1];
	dp[0][2] = dp[0][2] = mat[0][2];

	for (int i = 1; i < N; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + mat[i][0];

		dp[i][1] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + mat[i][1];

		dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + mat[i][2];
	}


	for (int i = 0; i < 3; i++) {
		MAX = max(MAX, dp[N - 1][i]);
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = 987654321;
		}
	}

	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + mat[i][0];

		dp[i][1] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + mat[i][1];

		dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + mat[i][2];
	}

	for (int i = 0; i < 3; i++) {
		MIN = min(MIN, dp[N - 1][i]);
	}

	cout << MAX << " " << MIN << "\n";

	return 0;
}
