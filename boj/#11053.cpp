#include<iostream>
#include<algorithm>

using namespace std;


int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, tmp;
	int A[1002] = { 0, }, dp[1002] = { 0, };

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int MAX = 0, ans = 0;

	for (int i = 0; i < N; i++) {
		MAX = 0;

		for (int j = 0; j < i; j++) {
			if (A[j] < A[i])
				MAX = max(MAX, dp[j]);
		}

		dp[i] = MAX + 1;
		ans = max(ans, dp[i]);
	}

	
	cout << ans << "\n";

	return 0;
}