#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<math.h>
#include<unordered_map>

using namespace std;

#define MAX 101

// 전역 변수
struct Edge {
	int a, b;
	float weight;

	Edge(int a, int b, float weight) :a(a), b(b), weight(weight) {}
};

int N;
int parent[MAX];
int ranks[MAX];
vector<Edge> edges;


// 함수
float calcDistance(pair<float, float> a, pair<float, float> b);
bool cmp(Edge a, Edge b);
int find(int x);
bool merge(int a, int b);
void init();

void init() {
	for (int i = 0; i < MAX; i++)
		parent[i] = i;

	for (int i = 0; i < MAX; i++)
		ranks[i] = 1;
}

float calcDistance(pair<float, float> a, pair<float, float> b) {
	float dist = sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
	return dist;
}

bool cmp(Edge a, Edge b) {
	return a.weight < b.weight;
}

int find(int x) {
	if (parent[x] == x)
		return x;

	int y = find(parent[x]);
	parent[x] = y;
	return y;
}

bool merge(int a , int b) {
	int x = find(a);
	int y = find(b);

	if (x == y)
		return false;

	if (ranks[y] < ranks[x]) {
		parent[y] = x;
		ranks[x] += ranks[y];
	}
	else {
		parent[x] = y;
		ranks[y] += ranks[x];
	}

	return true;
}

float kruskal() {
	float ret = 0;

	for (int i = 0; i < edges.size(); i++) {
		int a = edges[i].a;
		int b = edges[i].b;
		float w = edges[i].weight;

		if(merge(a, b))
			ret += w;
	}

	return ret;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	cin >> N;

	float x, y;
	vector<pair<float, float>> points;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		points.push_back({ x, y });
	}

	for (int i = 0; i < points.size(); i++) {
		for (int j = i + 1; j < points.size(); j++) {
			float dist = calcDistance(points[i], points[j]);
			edges.push_back(Edge(i, j, dist));
		}
	}

	sort(edges.begin(), edges.end(), cmp);

	cout << kruskal();

	return 0;
}