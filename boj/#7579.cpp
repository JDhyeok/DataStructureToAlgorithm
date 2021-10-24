#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

int N, M;
int dp[101][100001];

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int tmp, costSum = 0;

	vector<int> Mem;
	vector<int> Cost;
	Mem.push_back(0);
	Cost.push_back(0);

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		Mem.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		costSum += tmp;
		Cost.push_back(tmp);
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= costSum; j++) {
			if (j >= Cost[i])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - Cost[i]] + Mem[i]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	for (int i = 0; i <= costSum; i++) {
		if (dp[N][i] >= M) {
			cout << i;
			break;
		}
	}

	return 0;
}
