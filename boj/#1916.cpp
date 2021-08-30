#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

#define INF 987654321

int N, M;
int dist[1001];
vector<pair<int, int>> vec[1001];

void dijkstra(int v) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push(make_pair(0, v));
	dist[v] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		if (dist[cur] < curCost)
			continue;

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first;
			int nextCost = vec[cur][i].second + curCost;

			if (dist[next] <= nextCost)
				continue;

			dist[next] = nextCost;
			pq.push(make_pair(nextCost, next));
		}
	}
}

int main() {

	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	cin >> N >> M;

	
	int a, b, c, strt, dest;
	

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
	}
	cin >> strt >> dest;

	fill_n(dist, 1001, INF);
	dijkstra(strt);

	cout << dist[dest] << "\n";

	return 0;
}
