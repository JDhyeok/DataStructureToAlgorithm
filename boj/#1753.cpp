#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<array>
#include<unordered_map>

using namespace std;

#define INF 20001
#define MAX 987654321

int V, E;
vector<pair<short, short>> vec[20001];


void dijkstra(int K, vector<int>& ans) {

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	
	
	pq.push(make_pair(0, K));
	ans[K] = 0;


	while (!pq.empty()) {
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		if (ans[cur] < curCost)
			continue;

		for (int i = 0; i < vec[cur].size(); i++) {
			if (ans[vec[cur][i].second] < vec[cur][i].first + curCost)
				continue;

			ans[vec[cur][i].second] = curCost + vec[cur][i].first;
			pq.push(make_pair(vec[cur][i].first + curCost, vec[cur][i].second));
		}

	}

}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> V >> E;

	int a, b, c, K;
	vector<int> ans(V + 1, MAX);

	cin >> K;

	for (int i = 0; i < E;i ++) {
		cin >> a >> b >> c;
		
		vec[a].push_back(make_pair(c, b));
	}

	dijkstra(K, ans);
	
	for (int i = 1; i <= V; i++) {
		if (ans[i] >= MAX)
			cout << "INF\n";
		else
			cout << ans[i] << "\n";
	}

	return 0;
}
