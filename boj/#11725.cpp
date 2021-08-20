#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

using namespace std;


// bfs
// time : 136ms
// memorty : 11700 KB
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	unordered_map<int, vector<int>> hash;
	queue<int> q;
	int root[100001] = { 0, };
	root[1] = 1;

	int N, a, b;

	cin >> N;

	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		hash[a].push_back(b);
		hash[b].push_back(a);
	}

	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < hash[cur].size(); i++) {
			if (root[hash[cur][i]] == 0) {
				root[hash[cur][i]] = cur;
				q.push(hash[cur][i]);
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << root[i] << "\n";
	}

	return 0;
}

// dfs
// time : 48ms
// memorty : 12584 KB
int N;
bool visited[100001];
int parent[100001];
vector<int> tree[100001];

void dfs(int root) {

	visited[root] = true;

	for (int i = 0; i < tree[root].size(); i++) {
		if (visited[tree[root][i]])
			continue;

		visited[tree[root][i]] = true;
		parent[tree[root][i]] = root;
		dfs(tree[root][i]);
		
	}
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);


	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";

	return 0;
}
