#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

using namespace std;

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
