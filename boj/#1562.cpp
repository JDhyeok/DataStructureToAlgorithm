#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

#define MOD 1000000000

int N;
int dp[101][10][1024];


int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// init
	for (int i = 1; i < 10; i++) {
		int tmp = 0 | (1 << i);
		dp[1][i][tmp] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 1024; k++) {
				int tmp = k | (1 << j);
				if (j == 0) {
					dp[i][j][tmp] += dp[i - 1][j + 1][k];
				}
				else if (j == 9) {
					dp[i][j][tmp] +=  dp[i - 1][j - 1][k];
				}
				else {
					dp[i][j][tmp] += dp[i - 1][j + 1][k] + dp[i - 1][j - 1][k];
				}
				dp[i][j][tmp] %= MOD;
			}
		}
	}

	int ans = 0;

	/*for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			int tmp = 0;
			for (int k = 0; k < 1024; k++) {
				tmp += dp[i][j][k];
			}
			cout << tmp << " ";
		}
		cout << "\n";
	}*/

	for (int j = 0; j < 10; j++) {
		ans += dp[N][j][1023];
		ans %= MOD;
	}
	
	cout << ans;

	return 0;
}
