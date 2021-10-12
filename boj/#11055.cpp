#include<iostream>

using namespace std;

#define MAX 1001

int N, A[MAX], dp[MAX], ans = 0;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	for (int i = 1; i <= N; i++) {
		dp[i] = A[i];
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i]) {
				dp[i] = max(dp[i], A[i] + dp[j]);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}