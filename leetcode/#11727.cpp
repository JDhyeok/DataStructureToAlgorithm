#include<iostream>

using namespace std;

#define MAX 1001

int n;

long long dp[MAX];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	dp[1] = 1;
	dp[2] = 3;
	
	for (int i = 3; i <= n; i++) {
		dp[i] = ((dp[i - 2] * 2) % 10007 + dp[i - 1] % 10007)%10007;
	}

	cout << dp[n] << "\n";

	return 0;
}
