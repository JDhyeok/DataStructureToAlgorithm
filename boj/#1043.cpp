#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

#define MAX 51

int N, M;
int parent[MAX];
unordered_map<int, int> know_truth;
unordered_map<int, vector<int>> attendees;

void init() {
	for (int i = 0; i < MAX; i++)
		parent[i] = i;
}

int find(int x) {
	if (parent[x] == x)
		return x;

	int y = find(parent[x]);
	parent[x] = y;
	return y;
}

void unions(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (a == b)
		return;

	if (know_truth[x] == 1)
		parent[y] = x;
	else if (know_truth[y] == 1)
		parent[x] = y;
	else
		parent[x] = y;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	cin >> N >> M;

	int tmp, per;

	cin >> tmp;

	for (int i = 0; i < tmp; i++) {
		cin >> per;
		know_truth[per]++;
	}

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			cin >> per;
			attendees[i+1].push_back(per);
		}
	}
	
	for (int i = 0; i < M; i++) {
		if (!attendees[i+1].empty()) {
			for (int j = 0; j < attendees[i+1].size(); j++) {
				unions(attendees[i+1][0], attendees[i+1][j]);
			}
		}
	}
	
	int cnt = M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < attendees[i + 1].size(); j++) {
			int isKnown = find(attendees[i+1][j]);
			if (know_truth[isKnown] > 0) {
				cnt--;
				break;
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}
