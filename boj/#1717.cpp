#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

#define MAX 1000001

int parent[MAX];
int ranks[MAX];
int n, m;

int find(int);
void _union(int, int);

void _union(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y) {
		return;
	}

	if (x < y) {
		parent[y] = x;
		ranks[x] += ranks[y];
	}
	else if (x > y) {
		parent[x] = y;
		ranks[y] += ranks[x];
	}
}

int find(int x) {
	if (parent[x] == x) {
		return x;
	}

	int y = find(parent[x]);
	parent[x] = y;
	return y;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < MAX; i++) {
		parent[i] = i;
		ranks[i] = 1;
	}

	cin >> n >> m;

	int a, b, c;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		if (a == 0) {
			_union(b, c);
		}
		else if (a == 1) {
			if (find(b) == find(c))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}
