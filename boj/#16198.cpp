#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, ans = 0;
vector<int> balls;

// 2020Kb 12ms solution
void dfs(vector<int> ball, int sum) {
	if (ball.size() == 2) {
		ans = max(ans, sum);
		return;
	}
	
	for (int i = 1; i < ball.size() - 1; i++) {
		int tmp = ball[i - 1] * ball[i + 1];

		vector<int> copied(ball.size());
		copy(ball.begin(), ball.end(), copied.begin());
		copied.erase(copied.begin() + i);

		dfs(copied, sum + tmp);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		balls.push_back(tmp);
	}
	
	dfs(balls, 0);

	cout << ans;

	return 0;
}

// 2020KB 0ms solution
int N, ans = 0;
bool selected[MAX];
vector<int> balls;

void dfs(int sum, int cnt) {
	if (N - cnt == 2) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 1; i < N - 1; i++) {
		if (selected[i])
			continue;

		selected[i] = true;
		int l = i, r = i;

		while (l >= 0 && l--) {
			if (selected[l] == false)
				break;
		}

		while (r < N && r++) {
			if (selected[r] == false)
				break;
		}

		dfs(sum + balls[l] * balls[r], cnt + 1);
		selected[i] = false;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fill_n(selected, MAX, false);

	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		balls.push_back(tmp);
	}
	
	dfs(0, 0);

	cout << ans;

	return 0;
}