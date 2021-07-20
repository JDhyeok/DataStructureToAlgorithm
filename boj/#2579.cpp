#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	int stairs[301] = { 0, };
	int dp[301] = { 0, };
	
	int n,  tmp;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		stairs[i] = tmp;
	}

	dp[0] = stairs[0];
	dp[1] = stairs[0] + stairs[1];
	dp[2] = max(stairs[0] + stairs[2], stairs[1]+stairs[2]);

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);

	}

	cout << dp[n - 1];

	return 0;
}