#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<array>
#include<unordered_map>

using namespace std;

#define MAX 100001

int N, ans = 0, farNode = 0;;
int dp[MAX] = { 0, };
bool visited[MAX];
vector<pair<int,int>> vec[MAX];


void dfs(int v, int dist) {
	if (visited[v])
		return;

	visited[v] = true;
	
	if (ans < dist) {
		ans = dist;
		farNode = v;
	}

	for (int i = 0; i < vec[v].size(); i++) {
		dfs(vec[v][i].first, dist + vec[v][i].second);
	}
	return;
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	int a, b, c;

	for (int i = 0; i < N -1;i ++) {
		cin >> a;

		while (1) {
			cin >> b;
			if (b == -1)
				break;

			cin >> c;

			vec[a].push_back(make_pair(b, c));
		}
	}

	fill_n(visited, MAX, false);
	fill_n(dp, MAX, 0);
	
	dfs(1, 0);

	fill_n(visited, MAX, false);
	fill_n(dp, MAX, 0);

	dfs(farNode, 0);

	cout << ans << "\n";

	return 0;
}
