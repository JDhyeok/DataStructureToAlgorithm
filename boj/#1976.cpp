#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<math.h>
#include<string>
#include<unordered_map>

using namespace std;

#define N_MAX 201

int N, M;
int adjMat[N_MAX][N_MAX];
int possible[N_MAX];
vector<int> plan;

// bfs 풀이법
void bfs(int x) {
	queue<int> q;

	possible[x] = true;
	q.push(x);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (adjMat[cur][i] && !possible[i]) {
				possible[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> adjMat[i][j];

	int tmp;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		plan.push_back(tmp);
	}
	
	fill_n(possible, N_MAX, false);

	bfs(plan[0]);

	bool ans = true;

	for (int i = 0; i < plan.size(); i++)
		if (!possible[plan[i]])
			ans = false;

	if (ans)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}

// union find 풀이

