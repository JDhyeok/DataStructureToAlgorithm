#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, M;
int ans = 987654321;
int dp[101] = { 987654321, };

void bfs(vector<pair<int, int>>& snakes, vector<pair<int, int>>& ladders) {
	
	fill_n(dp, 101, 987654321);
	dp[1] = 0;
	queue<pair<int, int>> q;
	bool moved;
	
	q.push(make_pair(1,0));


	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		if (cur.first == 100) {
			ans = min(ans, cur.second);
			
		}


		moved = false;

		// snake check
		for (int i = 0; i < snakes.size(); i++) {
			if (snakes[i].first == cur.first) {
				q.push(make_pair(snakes[i].second, cur.second));
				moved = true;
				break;
			}
		}
		if (moved)
			continue;

		// ladder check
		for (int i = 0; i < ladders.size(); i++) {
			if (ladders[i].first == cur.first) {
				q.push(make_pair(ladders[i].second, cur.second));
				moved = true;
				break;
			}
		}
		if (moved)
			continue;

		for (int i = 1; i <= 6; i++) {
			int next = cur.first + i;
			if (next > 100)
				break;

			if (dp[next] < cur.second + 1)
				continue;

			q.push(make_pair(next, cur.second + 1));
			dp[next] = cur.second + 1;
		}
	}
}

int main() {
	
	int a, b;
	vector<pair<int, int>> ladders;
	vector<pair<int, int>> snakes;


	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		ladders.push_back(make_pair(a, b));
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		snakes.push_back(make_pair(a, b));
	}

	bfs(snakes, ladders);

	cout << ans;

	return 0;
}