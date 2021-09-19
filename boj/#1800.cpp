#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<math.h>
#include<string>
#include<unordered_map>

using namespace std;

#define N_MAX 1001
#define P_MAX 10001

int N, P, K, ans = -1;
int dist[N_MAX];
priority_queue<int> vertex[N_MAX];
vector<pair<int, int>> edges[P_MAX];

bool dijkstra(int x) {
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

	fill_n(dist, N_MAX, 987654321);

	pq.push({ 0,1 });
	dist[1] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

	
		if (dist[cur] < curCost)
			continue;

		for (int i = 0; i < edges[cur].size(); i++) {
			int next = edges[cur][i].first;
			int nextCost = curCost + (edges[cur][i].second > x);

			if (nextCost < dist[next]) {
				dist[next] = nextCost;
				pq.push({ nextCost, next });
			}

		}
	}

	return dist[N] <= K;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	cin >> N >> P >> K;

	int a, b, c, maxEdge = 0;
	for (int i = 0; i < P; i++) {
		cin >> a >> b >> c;
		edges[a].push_back({ b ,c });
		edges[b].push_back({ a, c });

		maxEdge = max(maxEdge, c);
	}

	int l = 0, r = maxEdge;

	while (l <= r) {
		int mid = (l + r) / 2;
		bool possible = dijkstra(mid);

		if (possible) {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans << "\n";

	return 0;
}
