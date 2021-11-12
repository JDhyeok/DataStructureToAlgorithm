#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct Planet {
	int num;
	int x, y, z;
	Planet(int num, int x, int y, int z) : num(num), x(x), y(y), z(z) {}
};

struct Edge {
	int a, b;
	int cost;
	Edge(int a, int b, int cost) : a(a), b(b), cost(cost) {}
};


struct cmp {
	bool operator() (Edge a, Edge b) {
		return a.cost > b.cost;
	}
};

bool cmp_x(Planet a, Planet b){
	return a.x < b.x;
}

bool cmp_y(Planet a, Planet b) {
	return a.y < b.y;
}

bool cmp_z(Planet a, Planet b) {
	return a.z < b.z;
}

#define MAX 300005

int N;
int parents[MAX], ranks[MAX];
vector<Planet> planet;
priority_queue<Edge, vector<Edge>, cmp> pq;

int find(int x) {
	if (parents[x] == x)
		return x;

	int y = find(parents[x]);
	parents[x] = y;
	return y;
}

bool merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y) 
		return false;
	

	if (ranks[x] <= ranks[y]) {
		parents[x] = y;
		ranks[y] += ranks[x];
	}
	else if (ranks[x] > ranks[y]) {
		parents[y] = x;
		ranks[x] += ranks[y];
	}

	return true;
}

int kruskal() {

	int ret = 0;

	while (!pq.empty()) {
		int a = pq.top().a;
		int b = pq.top().b;
		int cost = pq.top().cost;
		pq.pop();

		if (merge(a, b)) {
			ret += cost;
		}
	}

	return ret;
}

void init() {
	for (int i = 1; i < MAX; i++) {
		parents[i] = i;
		ranks[i] = 1;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	cin >> N;

	int a, b, c;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b >> c;
		planet.push_back(Planet(i, a, b, c));
	}

	// x로 정렬
	sort(planet.begin(), planet.end(), cmp_x);
	for (int i = 1; i < planet.size(); i++) {
		int a = planet[i - 1].num;
		int b = planet[i].num;
		int cost = abs(planet[i - 1].x - planet[i].x);

		pq.push(Edge(a, b, cost));
	}

	// y로 정렬
	sort(planet.begin(), planet.end(), cmp_y);
	for (int i = 1; i < planet.size(); i++) {
		int a = planet[i - 1].num;
		int b = planet[i].num;
		int cost = abs(planet[i - 1].y - planet[i].y);

		pq.push(Edge(a, b, cost));
	}

	// z로 정렬
	sort(planet.begin(), planet.end(), cmp_z);
	for (int i = 1; i < planet.size(); i++) {
		int a = planet[i - 1].num;
		int b = planet[i].num;
		int cost = abs(planet[i - 1].z - planet[i].z);

		pq.push(Edge(a, b, cost));
	}

	cout << kruskal();

	return 0;
}
