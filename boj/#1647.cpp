#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

#define MAX 100001

int N, M;


struct Edge {
	int a, b;
	Edge(int a, int b) :a(a), b(b) {}
};

class cmp {
public:
	bool operator()(pair<int, Edge> a, pair<int, Edge> b) {
		return a.first > b.first;
	}
};

int parent[MAX];
int ranks[MAX];

priority_queue <pair<int, Edge>, vector<pair<int, Edge>>, cmp> pq;

void init();
int find(int);
bool merge(int, int);
int kruskal();

void init() {
	for (int i = 0; i < MAX; i++)
		parent[i] = i;

	for (int i = 0; i < MAX; i++)
		ranks[i] = 1;
}

int find(int x) {
	if (parent[x] == x)
		return x;

	int y = find(parent[x]);
	parent[x] = y;
	return y;
}

bool merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y)
		return false;

	if (ranks[x] < ranks[y]) {
		parent[y] = x;
		ranks[x] += ranks[y];
	}
	else {
		parent[y] = x;
		ranks[x] += ranks[y];
	}

	return true;
}

int kruskal() {

	int ret = 0, remove = 0;

	while (!pq.empty()) {
		int a = pq.top().second.a;
		int b = pq.top().second.b;
		int w = pq.top().first;
		pq.pop();

		if (merge(a, b)) {
			ret += w;
			remove = max(remove, w);
		}
	}

	return ret - remove;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	cin >> N >> M;

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		pq.push(make_pair(c, Edge(a,b)));
	}

	cout << kruskal();

	return 0;
}
