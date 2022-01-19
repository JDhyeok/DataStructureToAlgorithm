#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
#include<unordered_map>

using namespace std;

#define MAX 2001

bool ans = false;
int N, M;
vector<int> friends[MAX];


void dfs(int depth, int cur, bool visited[]) {
	if (depth == 5) {
		ans = true;
		return;
	}

	for (int i = 0; i < friends[cur].size(); i++) {
		if (visited[friends[cur][i]])
			continue;

		visited[friends[cur][i]] = true;
		dfs(depth + 1, friends[cur][i], visited);
		visited[friends[cur][i]] = false;
	}

}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool visited[2001];
	

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		fill_n(visited, MAX, false);
		visited[i] = true;
		if (!ans)
			dfs(1, i, visited);
		else
			break;
	}

	cout << ans;

	return 0;
}