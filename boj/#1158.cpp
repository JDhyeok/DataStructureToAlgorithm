#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int N, K;
vector<int> cq;

int main() {

	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cq.push_back(i);

	int tmp = K - 1;

	cout << "<";
	for (int i = 0; i < N; i++) {
		if (i == N - 1) {
			cout << cq[tmp] << ">";
			break;
		}
		cout << cq[tmp] << ", ";
		cq[tmp] = -1;
		tmp %= N;

		int cnt = 0;
		while (cnt < K) {
			tmp++;
			tmp %= N;
			if (cq[tmp] > 0)
				cnt++;
		}
		
	}

	return 0;
}
