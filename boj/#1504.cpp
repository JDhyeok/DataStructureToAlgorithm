#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<unordered_map>

using namespace std;

#define INF 999999999

int N, E, a, b, c;
int v1, v2;
int matrix[802][802];

// Floyd-Warshall 알고리즘을 이용한 풀이 O(N^3)
void floyd() {

	for (int m = 1; m <= N; m++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				matrix[s][e] = min(matrix[s][e], matrix[s][m] + matrix[m][e]);
			}
		}
	}
	
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> E;

	for (int i = 0; i < 802; i++) {
		for (int j = 0; j < 802; j++) {
			matrix[i][j] = INF;
			if (i == j)
				matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		matrix[a][b] = c;
		matrix[b][a] = c;
	}
	
	cin >> v1 >> v2;


	floyd();

	if (matrix[1][v1] >= INF || matrix[1][v2] >= INF || matrix[v1][v2] >= INF || matrix[v2][N] >= INF || matrix[v1][N] >= INF) {
		// 중간 연결이 끊겼을 때
		cout << -1 << "\n";
		return 0;
	}

	int way1, way2;

	// 1 > v1 > v2 > N
	way1 = matrix[1][v1] + matrix[v1][v2] + matrix[v2][N];

	// 1 > v2 > v1 > N
	way2 = matrix[1][v2] + matrix[v2][v1] + matrix[v1][N];

	int ans = min(way1, way2);

	cout << ans << "\n";

	return 0;
}


// Dijkstra 알고리즘을 사용한 풀이  O(E logE)

vector<int> dijkstra(int start) {
	vector<int> distance(N+1, INF);
	vector<int> visited(N + 1, false);

	distance[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, start));
	visited[start] = true;

	while (!q.empty()) {
		int cost = q.top().first;
		int cur = q.top().second;
		q.pop();

		if (distance[cur] < cost)
			continue;

		for (int i = 1; i <= N; i++) {

			if (matrix[cur][i] != INF) {
				if (cost + matrix[cur][i] < distance[i]) {
					distance[i] = cost + matrix[cur][i];
					q.push(make_pair(cost + matrix[cur][i], i));
				}
			}
		}
	}

	return distance;
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> E;

	for (int i = 0; i < 802; i++) {
		for (int j = 0; j < 802; j++) {
			matrix[i][j] = INF;
			if (i == j)
				matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		matrix[a][b] = c;
		matrix[b][a] = c;
	}
	
	cin >> v1 >> v2;

	vector<int> ret = dijkstra(1);
	vector<int> tmp1 = dijkstra(v1);
	vector<int> tmp2 = dijkstra(v2);


	int ans = min(ret[v1] + tmp1[v2] + tmp2[N], ret[v2] + tmp2[v1] + tmp1[N]);
	
	if (ans >= INF || ans < 0)
		cout << -1 << "\n";
	else
		cout << ans << "\n";

	return 0;
}
