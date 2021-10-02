#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int N;
long long B;

vector<vector<int>> multiple(vector<vector<int>>& X, vector<vector<int>>& Y) {
	vector<vector<int>> ret(X.size(), vector<int>(X.size(), 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				ret[i][j] += X[i][k] * Y[k][j];
			}
			ret[i][j] %= 1000;
		}
	}

	return ret;
}

vector<vector<int>> matMult(vector<vector<int>> mat, long long n) {
	if (n == 1)
		return mat;

	vector<vector<int>> ret(mat.size(), vector<int>(mat.size(), 0));

	for (int i = 0; i < N; i++)
		ret[i][i] = 1;

	while (n > 0) {
		if (n % 2 == 1) {
			ret = multiple(ret, mat);
		}
		n /= 2;
		mat = multiple(mat, mat);
	}
	return ret;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> B;

	int tmp;
	vector<vector<int>> mat;

	for (int i = 0; i < N; i++) {
		vector<int> col;
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			col.push_back(tmp % 1000);
		}
		mat.push_back(col);
	}
			
	vector<vector<int>> ans = matMult(mat, B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}