#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


/*struct Point {
	int v1, v2;
	Point(int a, int b) : v1(a), v2(b) { }
};*/

//vector<pair<int, Point>> edges;
vector<pair<int, int>> edges[1001];
int N, M, X;

vector<int> dijkstra(int a) {

	vector<int> dist(N+1, 987654321);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	dist[a] = 0;
	pq.push({0, a});
	

	while (!pq.empty()) {
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		// 현재 있는 거리 보다 크면 pass
		if (dist[cur] < curCost)
			continue;

		dist[cur] = curCost;

		// 다음 갈 곳 push
		for (int i = 0; i < edges[cur].size(); i++) {
			int next = edges[cur][i].second;
			int cost = edges[cur][i].first + curCost;

			if (dist[next] > cost) {
				pq.push({ cost, next });
			}
		}
	}

	return dist;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> X;

	int a, b, c;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		edges[a].push_back(make_pair(c, b));
	}

	// X에서 다른 모든 곳으로 가는 최단거리 구하기
	vector<int> X_starter;
	X_starter = dijkstra(X);

	int ans = 0;
	vector<int> i_starter;
	for (int i = 1; i <= N; i++) {
		if (X == i)
			continue;

		i_starter.clear();
		i_starter = dijkstra(i);

		ans = max(ans, X_starter[i] + i_starter[X]);
	}

	cout << ans << "\n";

	return 0;
}
