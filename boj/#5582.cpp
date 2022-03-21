#include<iostream>
#include<queue>
#include<string>
#include<math.h>
#include<time.h>
#include<algorithm>

using namespace std;

#define MAX 4001

string A, B;
int dp[MAX][MAX];

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> A >> B;

	int a_size = A.size();
	int b_size = B.size();

	for (int i = 0; i <= a_size; i++) {
		for (int j = 0; j <= b_size; j++) {
			dp[i][j] = 0;
		}
	}

	int ans = 0;

	for (int i = 1; i <= a_size; i++) {
		for (int j = 1; j <= b_size; j++) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(ans, dp[i][j]);
			}
			else {
				dp[i][j] = 0;
			}
		}
	}

	cout << ans;
	
	return 0;
}