#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int N;

int main() {

	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	cin >> N;
	long long dp[100001];
	dp[0] = 1;
	dp[1] = 3;
	dp[2] = 7;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
	}
	
	cout << (dp[N] % 9901) << "\n";

	return 0;
}
