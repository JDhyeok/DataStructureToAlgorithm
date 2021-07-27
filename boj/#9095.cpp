#include<iostream>

using namespace std;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T, n;
	int dp[11];

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;

		cout << dp[n] << "\n";
	}
	

	
	return 0;
}