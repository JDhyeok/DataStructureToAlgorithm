#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, ans = 0;
int dp[10001] = { 0, };
bool visited[10001];
vector<pair<int,int>> vec[10001];


void dfs(int v, int dist) {
	visited[v] = true;
	if (dp[v] != 0) {
		ans = max(ans, dist + dp[v]);
		return;
	}

	for (int i = 0; i < vec[v].size(); i++) {
		if (visited[vec[v][i].first])
			continue;
		ans = max(ans, dist + vec[v][i].second);
		dp[v] = ans;
		dfs(vec[v][i].first, dist + vec[v][i].second);
	}
	return;
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	int a, b, c;

	for(int i = 0 ;i  < N-1;i++){
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
		vec[b].push_back(make_pair(a, c));
	}
	
	for (int i = 1; i <= N; i++) {
		fill_n(visited, 10001, false);
		fill_n(dp, 10001, 0);
		dfs(i, 0);
	}

	cout << ans << "\n";

	return 0;
}
