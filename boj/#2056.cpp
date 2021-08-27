#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
vector<int> vec[10001];
vector<int> times;
int dp[10001] = { 0, };

int dfs(int init) {

	if (dp[init] != 0)
		return dp[init];

	int t = 0;

	for (int i = 0; i < vec[init].size(); i++) {
		t = max(t, dfs(vec[init][i]));
	}
	dp[init] = t + times[init - 1];
	return t + times[init-1];
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int time, num, node;
	vector<int> init;

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> time >> num;
		if (num == 0) {
			init.push_back(i);
		}
		times.push_back(time);
		for (int j = 0; j < num; j++) {
			cin >> node;
			vec[i].push_back(node);
		}
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		ans = max(ans, dfs(i));
	}

	cout << ans;

	return 0;
}

// O(N) 풀이
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	int ans = 0;
	array<int, 10001> work;

	for (int i = 1; i <= N; i++) {
		int t, pre, cost = 0;
		cin >> t >> pre;
		for (int j = 0; j < pre; j++) {
			int p;
			cin >> p;
			cost = max(cost, work[p]);
		}
		work[i] = t + cost;
		ans = max(ans, work[i]);
	}
	cout << ans;
	return 0;
}
