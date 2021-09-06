#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int N;
int dp[1000001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[N];
	
	return 0;
}
