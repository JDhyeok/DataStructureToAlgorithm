#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<math.h>
#include<string>
#include<unordered_map>

using namespace std;

#define MAX 501

int N;
int dp[MAX];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;


	int ans = 0;

	for (int i = 1; i <= N; i++) {
		int tmp = i;

		if (i % 100 == 0) {
			tmp /= 100;
			ans += 2;
		}
		else if (i % 10 == 0) {
			tmp /= 10;
			ans++;
		}

		if (tmp % 125 == 0)
			ans += 3;
		else if (tmp % 25 == 0)
			ans += 2;
		else if (tmp % 5 == 0)
			ans++;

	}

	cout << ans << "\n";

	return 0;
}
