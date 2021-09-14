#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

#define N_MAX 1001

struct Point {
	int a;
	int b;
	Point(int x, int y) :a(x), b(y) {}
};

int parent[N_MAX];
int ranks[N_MAX];
int N, M;

void init() {
	for (int i = 0; i < N_MAX; i++)
		parent[i] = i;

	for (int i = 0; i < N_MAX; i++)
		ranks[i] = 1;
}

int find(int x) {
	if (parent[x] == x)
		return x;

	int y = find(parent[x]);
	parent[x] = y;
	return y;
}

bool cmp(pair<int, Point> a, pair<int, Point> b) {
	return a.first < b.first;
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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, Point>> costs;

	init();

	cin >> N >> M;

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		costs.push_back({ c, Point(a,b) });
	}

	sort(costs.begin(), costs.end(), cmp);


	int ans = 0;

	for (int i = 0; i < costs.size(); i++) {
		bool flag = unions(costs[i].second.a, costs[i].second.b);
		if (flag) {
			ans += costs[i].first;
		}
	}

	cout << ans << "\n";

	return 0;
}
