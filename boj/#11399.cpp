#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, tmp;
	vector<int> P;

	cin >> N;
	

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		P.push_back(tmp);
	}

	sort(P.begin(), P.end());

	for (int i = 1; i < N; i++) {
		P[i] += P[i - 1];
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += P[i];
	}

	cout << ans << "\n";

	return 0;
}
