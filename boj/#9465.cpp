#include<iostream>

using namespace std;

#define MAX 100001

int T, N;
int sticker[2][MAX];
int dp[2][MAX];



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> sticker[i][j];
			}
		}

		for (int i = 0; i < 2; i++) {
			dp[0][i] = 0;
			dp[1][i] = 0;
		}
		
		int ans = 0;

		dp[0][1] = sticker[0][0];
		dp[1][1] = sticker[1][0];

		ans = max(dp[0][1], dp[1][1]);

		int tmp;
		for (int i = 2; i <= N; i++) {
			dp[0][i] = sticker[0][i - 1];
			dp[1][i] = sticker[1][i - 1];
			
			tmp = max(dp[0][i - 2] + dp[0][i], dp[1][i - 2] + dp[0][i]);
			dp[0][i] = max(dp[1][i-1] + dp[0][i], tmp);

			tmp = max(dp[1][i - 2] + dp[1][i], dp[0][i - 2] + dp[1][i]);
			dp[1][i] = max(dp[0][i - 1] + dp[1][i], tmp);

			ans = max(dp[0][i], dp[1][i]);
		}


		cout << ans << "\n";
	}


	return 0;
}