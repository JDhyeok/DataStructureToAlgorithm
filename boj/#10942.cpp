#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

#define MAX 2001

int N, M, nums[MAX];
int dp[MAX][MAX];
// 0 : 방문하지 않음, 1 : 방문 했으나 palindrome 아님, 2 : 방문 했고 palindrome 이다

int helper(int s, int e) {
	if (dp[s][e] > 0)
		return dp[s][e];

	if (nums[s] == nums[e] && s + 1 == e) {
		dp[s][e] = 2;
		return dp[s][e];
	}

	if (nums[s] == nums[e]) {
		dp[s][e] = helper(s + 1, e - 1);
		return dp[s][e];
	}
	
	dp[s][e] = 1;
	return dp[s][e];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// init
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			dp[i][j] = 0;
			if (i == j)
				dp[i][j] = 2;
		}
	}

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
	}

	cin >> M;

	int s, e;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;

		int tmp;

		if (dp[s][e] > 0)
			cout << dp[s][e] - 1 << "\n";
		else
			cout << helper(s, e) - 1 << "\n";
	}


	return 0;
}
