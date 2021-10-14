#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

#define MAX 2001

int N, M, small, big;
bool visited[MAX];
vector<int> bigger[MAX];
vector<int> smaller[MAX];

void dfsBigger(int cur) {

	visited[cur] = true;
	big++;

	for (int i = 0; i < bigger[cur].size(); i++) {
		if(!visited[bigger[cur][i]])
			dfsBigger(bigger[cur][i]);
	}
}

void dfsSmaller(int cur) {
	visited[cur] = true;
	small++;

	for (int i = 0; i < smaller[cur].size(); i++) {
		if (!visited[smaller[cur][i]])
			dfsSmaller(smaller[cur][i]);
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		bigger[a].push_back(b);
		smaller[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		small = 0, big = 0;

		fill_n(visited, MAX, false);
		dfsBigger(i);
		fill_n(visited, MAX, false);
		dfsSmaller(i);

		int ans = N + 1 - small - big;

		cout << ans << "\n";
	}

	return 0;
}
