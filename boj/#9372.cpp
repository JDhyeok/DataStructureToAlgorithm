#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
#include<unordered_map>

using namespace std;

int T, N, M, a, b;
bool visited[1001];
vector<int> adjList[1001];

int bfs() {
	int ret = 0;
	queue<int> q;

	q.push(a);
	visited[a] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < adjList[cur].size(); i++) {
			if (!visited[adjList[cur][i]]){
				visited[adjList[cur][i]] = true;
				q.push(adjList[cur][i]);
				ret++;
			}
		}
	}
	return ret;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	

	cin >> T;

	while (T--) {

		for (int i = 0; i < 1001; i++)
			adjList[i].clear();
		fill_n(visited, 1001, false);

		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			adjList[a].push_back(b);
			adjList[b].push_back(a);
		}

		cout << bfs() << "\n";
	}

	

	return 0;
}