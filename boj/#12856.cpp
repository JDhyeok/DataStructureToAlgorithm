#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

int N, K;
int dp[102][100002] = { 0 , };
vector<int> weights;
vector<int> values;


int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> K;

	int w, v;

	for (int i = 0; i < N; i++) {
		cin >> w >> v;
		weights.push_back(w);
		values.push_back(v);
	}

	for (int i = 1; i <= N; i++) {
		for (int w = 0; w <= K; w++) {
			if (weights[i-1] <= w) {
				dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i - 1][w]);
			}
			else
				dp[i][w] = dp[i - 1][w];
		}
	}


	cout << dp[N][K];

	return 0;
}
