#include<iostream>

using namespace std;

int N, L;
vector<int> ans;

int Sn(int n) {
	return (n * (n + 1)) / 2;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;


	for (int i = L; i <= 100; i++) {
		int tmp = N - Sn(i - 1);
		if (tmp < 0)
			continue;
		if (tmp % i == 0) {
			tmp = tmp / i;
			for (int j = 0; j < i; j++) {
				ans.push_back(tmp++);
			}
			break;
		}
	}

	if (ans.empty())
		cout << -1;
	else {
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
	}

	return 0;
}