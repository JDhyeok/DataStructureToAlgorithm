#include<iostream>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;


int main() {

	priority_queue<int, vector<int>,greater<int>> neg;
	priority_queue<int, vector<int>, greater<int>> pos;

	vector<int> order;

	int N, x;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;


		if (x < 0) {
			neg.push(abs(x));
		}
		else if (x > 0) {
			pos.push(x);
		}
		else if (x == 0) {
			if (neg.empty() && pos.empty()) {
				cout << "0\n";
				continue;
			}

			if (!neg.empty() && pos.empty()) {
				cout << -neg.top() << "\n";
				neg.pop();
				continue;
			}
			else if (neg.empty() && !pos.empty()) {
				cout << pos.top() << "\n";
				pos.pop();
				continue;
			}

			int negNum = neg.top();
			int posNum = pos.top();

			if (negNum <= posNum) {
				cout << -negNum << "\n";
				neg.pop();
			}
			else {
				cout << posNum << "\n";
				pos.pop();
			}

		}
		
	}

}