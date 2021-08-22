#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<unordered_map>

using namespace std;

int n;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<vector<int>> tri;
	vector<int> tmp;
	int num;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		tmp.clear();
		for (int j = 0; j < i + 1; j++) {
			cin >> num;
			tmp.push_back(num);
		}
		tri.push_back(tmp);
	}

	int dp[501][501] = { 0, };
	dp[0][0] = tri[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < tri[i].size(); j++) {
			if (j == 0) {
				dp[i][j] = tri[i][j] + dp[i - 1][j];
			}
			else if (j == tri[i].size() - 1) {
				dp[i][j] = tri[i][j] + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(tri[i][j] + dp[i-1][j-1], tri[i][j] + dp[i - 1][j]);
			}
		}
	}


	int ans = -1;

	for (int i = 0; i < tri[n - 1].size(); i++) {
		ans = max(ans, dp[n - 1][i]);
	}

	cout << ans << "\n";

	return 0;
}
