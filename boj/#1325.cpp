#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 10001

int N, M;
vector<int> adjList[MAX];

int bfs(int start) {
	int ret = 1;

	bool visited[MAX];
	fill_n(visited, MAX, false);

	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < adjList[cur].size(); i++) {
			if (visited[adjList[cur][i]] == false) {
				ret++;
				q.push(adjList[cur][i]);
				visited[adjList[cur][i]] = true;
			}
		}
	}

	return ret;
}

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		adjList[b].push_back(a);
	}
	
	vector<pair<int, int>> ans;
	int max_infected = 0;

	for (int i = 1; i <= N; i++) {
		int tmp = bfs(i);
		max_infected = max(max_infected, tmp);
		ans.push_back({ tmp, i });
	}

	sort(ans.begin(), ans.end(), cmp);

	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].first == max_infected) {
			cout << ans[i].second;
		}
		else
			break;
		cout << " ";
	}

	return 0;
}
