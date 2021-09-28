#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
#include<unordered_map>

using namespace std;

#define MAX 1001

int N;
int A[MAX], dp[MAX];

int bitonic(int n) {
	int ans = 0, tmp = 0;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	ans += dp[n];

	dp[n] = 1;
	for (int i = n; i < N; i++) {
		for (int j = n; j < i; j++) {
			if (A[i] < A[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				tmp = max(tmp, dp[i]);
			}
		}
	}
	if(tmp != 0)
		ans += tmp - 1;

	return ans;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int ans = 0;
	for (int i = 0; i < N; i++) {
		fill_n(dp, MAX, 1);
		ans = max(ans, bitonic(i));
	}

	cout << ans << "\n";

	return 0;
}