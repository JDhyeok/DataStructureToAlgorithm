#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

#define MAX 10001

int N, M;
long long A[MAX];
long long dp[MAX];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> A[i];


	// O(N) 풀이법
	long long l = 0, r = 0, sum = 0, ans = 0;

	while (l <= r && r <= N) {

		if (sum < M) {
			if (r > N)
				break;
			sum += A[r];
			r++;
		}
		else if (sum >= M) {
			if (l > N)
				break;
			sum -= A[l];
			l++;

		}

		if (sum == M)
			ans++;

	}

	cout << ans;

    // O(NlogN) 풀이법
    for (int i = 1; i <= N; i++)
		dp[i] = dp[i - 1] + A[i - 1];

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		long long tmp = dp[i] - M;

		int idx = lower_bound(dp, dp + i, tmp) - dp;

		if (idx <= N && dp[idx] == tmp) {
			ans++;
		}
	}

    cout << ans;

	return 0;
}
