#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool visited[1001] = { false, };

void bfs(int cur, vector<pair<int, int>>& v) {
	queue<int> q;
	q.push(cur);
	visited[cur] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto next : v) {
			
			if (next.first == cur && visited[next.second] == false) {
				q.push(next.second);
				visited[next.second] = true;
			}
			else if (next.second == cur && visited[next.first] == false) {
				q.push(next.first);
				visited[next.first] = true;
			}
		}
	}
}

void dfs() {

}

int main() {
	int N, M;
	int x, y;
	int ans = 0;

	vector<pair<int, int>> v;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	for (int i = 1; i <= N; i++) {

		if (visited[i] == false) {
			ans++;
			bfs(i, v);
		}
	}
	cout << ans;
}