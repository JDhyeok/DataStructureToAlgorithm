#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

#define MAX 10001

struct Point {
	int v1, v2;
	Point(int x, int y) : v1(x), v2(y) {}
};

int V, E;
int a, b, c;

int parent[MAX];
int ranks[MAX];

int find(int x) {
	if (parent[x] == x)
		return x;

	int y = find(parent[x]);
	parent[x] = y;
	return y;
}

bool unions(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y)
		return false;

	if (ranks[x] < ranks[y]) {
		parent[x] = y;
		ranks[y] += ranks[x];
	}
	else {
		parent[y] = x;
		ranks[x] += ranks[y];
	}

	return true;
}

bool cmp(pair<int, Point> a, pair<int, Point> b) {
	return a.first < b.first;
}

void init() {
	for (int i = 0; i < MAX; i++)
		parent[i] = i;

	for (int i = 0; i < MAX; i++)
		ranks[i] = 1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	int ans = 0;

	vector<pair<int, Point>> edges;

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;

		edges.push_back(make_pair(c, Point(a,b)));
	}

	sort(edges.begin(), edges.end(), cmp);

	for (int i = 0; i < edges.size(); i++) {
		bool isCycle = unions(edges[i].second.v1, edges[i].second.v2);
		if (isCycle) {
			ans += edges[i].first;
		}
	}

	cout << ans << "\n";

	return 0;
}
