#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int T, k;


int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	char order;
	int number;
	bool visited[1000001] = { false, };
	int i = 0, j = 0;

	cin >> T;
	
	for (int t = 0; t < T; t++) {
		cin >> k;

		priority_queue<pair<int, int>> maxQ;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minQ;

		for (int i = 0; i < k; i++) {
			cin >> order >> number;
			
			switch (order) {
			case 'D':
				if (minQ.empty() && maxQ.empty())
					break;
				if (number == 1) {
					while (!maxQ.empty() && visited[maxQ.top().second]) maxQ.pop();

					if (!maxQ.empty()) {
						visited[maxQ.top().second] = true;
						maxQ.pop();
					}
				}
				else if (number == -1) {
					while (!minQ.empty() && visited[minQ.top().second]) minQ.pop();

					if (!minQ.empty()) {
						visited[minQ.top().second] = true;
						minQ.pop();
					}
				}
				break;
			case 'I':
				maxQ.push(make_pair(number, i));
				minQ.push(make_pair(number, i));
				break;
			}

		}

		while (!minQ.empty() && visited[minQ.top().second]) minQ.pop();
		while (!maxQ.empty() && visited[maxQ.top().second]) maxQ.pop();

		if (minQ.empty() && maxQ.empty())
			cout << "EMPTY\n";
		else
			cout << maxQ.top().first << " " << minQ.top().first << "\n";

		fill_n(visited, 1000001, false);
	}

	return 0;
}