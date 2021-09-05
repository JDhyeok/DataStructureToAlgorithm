#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int N;
int T[1001];
int P[1001];
int dp[1001] = { 0, };

int main() {

	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	cin >> N;

	int t, p;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
		
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		// 업무 기간이 마지막 날보다 짧으면 dp에 삽입
		if(N + 1 - i >= T[i])
			dp[i] = P[i];

		// 이전에 봤던 업무 중에 가장 비용을 크게 낼 수 있는 업무와 합침
		// 단, 업무 기간이 맞아야 하도록
		for (int j = 1; j < i; j++) {
			if (i - j >= T[j]) {
				if (N + 1 - i >= T[i]) {
					dp[i] = max(dp[i], dp[j] + P[i]);
				}
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans << "\n";

	return 0;
}
