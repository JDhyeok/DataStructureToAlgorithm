#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

#define MAX 100000001

int N, S;
long long nums[100001];
long long dp[100001];

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		dp[i + 1] = nums[i] + dp[i];
	}

	int l = 0, r = 0, ans = MAX;

	while (l <= N && l <= r) {
		long long sum = dp[r] - dp[l];

		if (sum < S) {
			if (r > N)
				break;
			r++;
		}
		else if (sum >= S) {
			ans = min(ans, r - l);
			l++;
		}
	}

	if (ans == MAX)
		cout << 0;
	else
		cout <<  ans;

	return 0;
}
