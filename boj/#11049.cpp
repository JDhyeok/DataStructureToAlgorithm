#include<iostream>
#include<vector>

using namespace std;

struct Matrix {
	int r, c;
	
	Matrix(int r, int c) : r(r), c(c) {}
};

int N;
int dp[500][500];
vector<Matrix> mat;

int solve(int s, int e) {
	// base case
	if (s == e)
		return 0;

	if (dp[s][e] != 0)
		return dp[s][e];

	if (s + 1 == e) {
		dp[s][e] = mat[s].r * mat[s].c * mat[e].c;
		return dp[s][e];
	}


	for (int i = s; i < e; i++) {
		int ret = solve(s, i) + solve(i + 1, e) + mat[s].r * mat[i].c * mat[e].c;
		if (dp[s][e] == 0 || ret < dp[s][e])
			dp[s][e] = ret;
	}

	return dp[s][e];
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;


	int r, c;
	while (N--) {
		cin >> r >> c;
		mat.push_back(Matrix(r, c));
	}

	solve(0, mat.size() - 1);

	cout << dp[0][mat.size() - 1];

	return 0;
}


// O(N^3)의 더 나은 풀이

int N;
int mat[501][2], dp[501][501];


int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> mat[i][0] >> mat[i][1];

	for (int i = 0; i < N; i++)
		dp[i][i + 1] = mat[i][0] * mat[i][1] * mat[i + 1][1];

	for (int m = 2; m <= N; m++) {				// 길이
		for (int i = 1; i <= N - m; i++) {		// 시작 위치
			int j = i + m;						// 끝 위치
			dp[i][j] = 987654321;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + (mat[i][0] * mat[k][1] * mat[j][1]));
			}
		}
	}

	cout << dp[1][N];
	return 0;
}
