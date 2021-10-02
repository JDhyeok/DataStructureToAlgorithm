#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

#define MAX 1000001

int N, A[MAX];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	vector<int> dp;

	dp.push_back(A[0]);
	for (int i = 1; i < N; i++) {
		if (dp.back() < A[i])
			dp.push_back(A[i]);
		else {
			int index = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
			dp[index] = A[i];
		}
	}

	cout << dp.size() << "\n";

	return 0;
}