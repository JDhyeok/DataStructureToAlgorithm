#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

#define MAX 16
#define INF 987654321

int N;
int W[MAX][MAX];
int dp[MAX][65537], visited = 0;

int tsp(int cur, int visited) {

	// 모든 도시를 방문 했다.
	if (visited == (1 << N) - 1) {
		// 현재 노드에서 출발 도시로 가는 것이 불가능하다.
		if (W[cur][0] == 0)
			return INF;

		return W[cur][0];
	}

	// 같은 도시를 순회하고 현재 도시를 방문한 적이 있다.
	if (dp[cur][visited] != 0)
		return dp[cur][visited];

	dp[cur][visited] = INF;

	for (int i = 0; i < N; i++) {
		int next = 1 << i;
		// 이미 방문했거나 갈 수 없을 때
		if (W[cur][i] == 0 || (visited & next) > 0)
			continue;

		// 방문한 도시 visited들을 가지고 있는 현재 도시 cur을 순회한 최소비용 업데이트
		dp[cur][visited] = min(dp[cur][visited], tsp(i, visited | next) + W[cur][i]);
	}

	return dp[cur][visited];
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	cout << tsp(0, 1) << "\n";

	return 0;
}