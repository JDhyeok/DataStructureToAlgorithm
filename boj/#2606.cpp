#include<iostream>
#include<queue>
#include<vector>

using namespace std;

bool visited[101] = { false, };

void bfs(vector<pair<int, int>>& net, int& ans) {
	
	queue<int> q;

	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto n : net) {
			if (n.first == cur && visited[n.second] == false) {
				q.push(n.second);
				ans++;
				visited[n.second] = true;
			}
			else if (n.second == cur && visited[n.first] == false) {
				q.push(n.first);
				ans++;
				visited[n.first] = true;
			}
		}
	}

	return;
}

int main() {

	int numCom, numNet;
	int x, y;

	vector<pair<int, int>> net;

	cin >> numCom >> numNet;

	for (int i = 0; i < numNet; i++) {
		cin >> x >> y;
		net.push_back(make_pair(x, y));
	}

	int ans = 0;
	bfs(net, ans);

	cout << ans;
	return 0;
}