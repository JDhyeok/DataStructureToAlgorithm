#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
#include<unordered_map>

using namespace std;

#define MAX 100004

int N, K;
int dp[MAX];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = MAX + 1;

	cin >> N >> K;
	
	// 걸어 갔을 때
	for (int i = 0; i < MAX; i++)
		dp[i] = abs(N - i);

	if (N < K) {
		for (int i = N + 1; i < 100003; i++) {
			if (i % 2 == 0) {
				dp[i] = min(dp[i/2], dp[i]);
				dp[i - 1] = min(dp[i - 1], dp[i] + 1);
			}
			else {
					dp[i] = min(dp[i], min(dp[i - 1] + 1, dp[i + 1] + 1));
			}
		}
	}


	cout << dp[K] << "\n";

	return 0;
}