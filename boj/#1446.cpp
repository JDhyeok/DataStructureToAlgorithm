#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
#include<unordered_map>

using namespace std;

struct Edge {
	int a;
	int b;
	int weight;

	Edge(int a, int b, int w) : a(a), b(b), weight(w) {}
};

int N, D;
int dp[10002];
vector<Edge> edges;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	fill_n(dp, 10001, 0);

	cin >> N >> D;

	int a, b, c;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;

		edges.push_back(Edge(a, b, c));
	}

	for (int cur = 1; cur <= D; cur++) {
		dp[cur] = dp[cur - 1] + 1;
		// 지름길 적용
		for (int e = 0; e < edges.size(); e++) {
			if (edges[e].b == cur) {
				dp[cur] = min(dp[cur], edges[e].weight + dp[edges[e].a]);
			}
		}
	}

	
	cout << dp[D];

	return 0;
}