#include<iostream>
#include<vector>

using namespace std;

int T, N, M;
vector<pair<int,int>> ans;

// vector 사용
// 2020 KB  /  0 ms
bool findGreater() {
	int score = ans[0].first;

	for (int i = 1; i < ans.size(); i++) {
		if (ans[i].first > score)
			return true;
	}
	return false;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;



	while (T--) {

		ans.clear();

		cin >> N >> M;
		
		int score;
		for (int i = 0; i < N; i++) {
			cin >> score;
			ans.push_back({ score, i });
		}

		int ret = 1;

		while (!ans.empty()) {
			bool greater = findGreater();
			if (greater) {
				ans.push_back({ans[0].first, ans[0].second});
				ans.erase(ans.begin());
			}
			else {

				if (ans[0].second == M) {
					cout << ret << "\n";
					break;
				}
				
				ret++;
				ans.erase(ans.begin());
			}
		}

	}
}


// Queue, Priority Queue 사용
// 2024 KB  /  0 ms

int T, N, M;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		priority_queue<int> pq;
		queue<pair<int, int>> q;

		cin >> N >> M;

		int score;
		for (int i = 0; i < N; i++) {
			cin >> score;
			q.push({ score, i });
			pq.push(score);
		}
		int ret = 1;
		while (!q.empty()) {
			

			int scr = q.front().first;
			int idx = q.front().second;
			q.pop();
			if (scr < pq.top()) {
				q.push({ scr, idx });
			}
			else {
				if (idx == M) {
					cout << ret << "\n";
					break;
				}
				ret++;
				pq.pop();
			}
		}
	}

	return 0;
}