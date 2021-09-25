#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

#define N_MAX 1000001

int N, M;
long long arr[N_MAX];

bool check(int height) {
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		long long sub = arr[i] - height;
		if (sub < 0)
			sub = 0;
		sum += sub;
	}
	if (sum >= M)
		return true;
	return false;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	long long l = 0, r = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		r = max(r, arr[i]);
	}

	long long ans = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;

		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << ans << "\n";

	return 0;
}