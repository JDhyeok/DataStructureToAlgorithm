#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
#include<unordered_map>

using namespace std;

#define MAX 100004

int N, K;
int dp[MAX];

// dp 풀이 0ms
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = MAX + 1;

	cin >> N >> K;
	
	// 걸어 갔을 때
	for (int i = 0; i < MAX; i++)
		dp[i] = abs(N - i);

	if (N < K) {
		for (int i = N + 1; i < 100003; i++) {
			if (i % 2 == 0) {
				dp[i] = min(dp[i/2], dp[i]);
				dp[i - 1] = min(dp[i - 1], dp[i] + 1);
			}
			else {
					dp[i] = min(dp[i], min(dp[i - 1] + 1, dp[i + 1] + 1));
			}
		}
	}


	cout << dp[K] << "\n";

	return 0;
}


// bfs 풀이 4ms
int N, K;
bool visited[MAX];

int bfs(int N, int K) {
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	visited[N] = true;
	pq.push({ 0,N });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int time = pq.top().first;
		pq.pop();

		if (cur == K)
			return time;

		if (cur * 2 < MAX && !visited[cur * 2]) {
			pq.push({ time, cur * 2 });
			visited[cur * 2] = true;
		}
		if (cur + 1 < MAX && !visited[cur + 1]) {
			pq.push({ time + 1, cur + 1 });
			visited[cur + 1] = true;
		}
		if (cur - 1 >= 0 && !visited[cur - 1]) {
			pq.push({ time + 1, cur - 1 });
			visited[cur - 1] = true;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	fill_n(visited, MAX, false);

	cin >> N >> K;
	
	cout << bfs(N, K) << "\n";
	
	return 0;
}