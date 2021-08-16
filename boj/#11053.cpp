#include<iostream>
#include<algorithm>

using namespace std;


int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, tmp;
	int A[1002] = { 0, }, dp[1002] = { 0, };

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int MAX = 0, ans = 0;

	for (int i = 0; i < N; i++) {
		MAX = 0;

		for (int j = 0; j < i; j++) {
			if (A[j] < A[i])
				MAX = max(MAX, dp[j]);
		}

		dp[i] = MAX + 1;
		ans = max(ans, dp[i]);
	}

	
	cout << ans << "\n";

	// 이분탐색을 이용한 풀이
	/*
	int N, ans = 0;
	int A[1002] = { 0, }, dp[1002] = { 0, };

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	vector<int> vec;

	for (int i = 0; i < N; i++) {
		if (vec.empty()) {
			vec.push_back(A[i]);
		}
		else {
			if (vec.back() < A[i])
				vec.push_back(A[i]);
			else {
				auto iter = lower_bound(vec.begin(), vec.end(), A[i]);
				*iter = A[i];
			}
		}
	}

	cout << vec.size() << "\n";
	*/

	return 0;
}