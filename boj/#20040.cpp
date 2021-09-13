#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

#define N_MAX 500000 + 1

int n, m;
int parent[N_MAX];
int ranks[N_MAX];

void initParent() {
	for (int i = 0; i < N_MAX; i++)
		parent[i] = i;
}

void initRanks() {
	fill_n(ranks, N_MAX, 1);
}

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
		ranks[x] = ranks[y];
	}
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	initParent();
	initRanks();

	cin >> n >> m;

	int a, b, ans = 0;
	bool isCycle = false;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		// 이미 사이클이 있다면 넘어감
		if (!isCycle) {
			bool tmp = unions(a, b);
			if (!tmp) {
				ans = i + 1;
				isCycle = true;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
