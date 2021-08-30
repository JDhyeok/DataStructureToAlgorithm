#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

#define INF 987654321

int N, M;
int dist[1001];
vector<pair<int, int>> vec[1001];
bool flag = false;
int ans[1001];

void dijkstra(int strt) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({0, strt});
	dist[strt] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		if (dist[cur] < curCost) {
			continue;
		}

		for (int i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].first;
			int nextCost = vec[cur][i].second + curCost;

			if (nextCost < dist[next]) {

				ans[next] = cur;
				dist[next] = nextCost;
				pq.push({nextCost, next});
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	fill_n(dist, 1001, INF);

	cin >> N >> M;

	int a, b, c;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		vec[a].push_back({b, c});
	}

	int strt, dest;

	cin >> strt >> dest;

	dijkstra(strt);


	cout << dist[dest] << "\n";

	int i = dest;
	vector<int> ret;

	while (i != strt) {
		ret.push_back(i);
		i = ans[i];
	}

	ret.push_back(i);

	cout << ret.size() << "\n";

	for (int i = ret.size() - 1; i >= 0; i--) {
		if (i == 0)
			cout << ret[i];
		else
			cout << ret[i] << " ";
	}

	return 0;
}
