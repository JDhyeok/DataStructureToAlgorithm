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

int calcCount(Matrix& A, Matrix& B) {
	return (A.r * A.c * B.c);
}

Matrix multMat(Matrix& A, Matrix& B) {
	return Matrix(A.r, B.c);
}

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
