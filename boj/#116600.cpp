#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

int N, M;
int x_1, x_2, y_1, y_2;
int mat[1024][1024];
int dp[1025][1025] = { 0, };
//int ans = 0;

int calc() {
	int ans = 0;
	for (int i = x_1; i <= x_2; i++) {
		ans += (dp[i][y_2] - dp[i][y_1 - 1]);
	}

	return ans;
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i][j - 1] + mat[i-1][j-1];
		}
	}
	

	for (int i = 0; i < M; i++) {
		cin >> x_1 >> y_1;
		cin >> x_2 >> y_2;


		cout << calc() << "\n";
	}



	return 0;
}
