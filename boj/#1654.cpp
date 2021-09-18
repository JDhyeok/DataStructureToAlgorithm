#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int K, N;
vector<long long> lans;

bool checkLans(long long len) {

	long long num = 0;

	for (int i = 0; i < lans.size(); i++) {
		num += lans[i] / len;
	}
	if (num >= N)
		return true;
	return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> K >> N;

	long long tmp, right = 0, left = 1, ans = 0;

	for (int i = 0; i < K; i++) {
		cin >> tmp;
		lans.push_back(tmp);
		right = max(right, tmp);
	}

	while (left <= right) {

		long long mid = (left + right) / 2;

		if (checkLans(mid)) {
			left = mid + 1;
			ans = mid;
		}
		else {
			right = mid - 1;
		}
		
	}

	cout << ans << "\n";

	return 0;
}
