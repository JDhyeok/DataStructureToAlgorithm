#include<iostream>
#include<vector>

using namespace std;

#define MAX 100000

vector<int> order;
int dp[MAX][5][5];

int calcEnergy(int from, int to) {
	if (from == to)
		return 1;
	if (from == 0)
		return 2;

	switch (from) {
	case 1:
		return to == 3 ? 4 : 3;
	case 2:
		return to == 4 ? 4 : 3;
	case 3:
		return to == 1 ? 4 : 3;
	case 4:
		return to == 2 ? 4 : 3;
	}
}

int solve(int step, int l, int r) {

	if (step == order.size())
		return 0;

	int& ret = dp[step][l][r];

	if (ret != 0)
		return ret;

	return ret = min(calcEnergy(l, order[step]) + solve(step + 1, order[step], r), calcEnergy(r, order[step]) + solve(step + 1, l, order[step]));
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int tmp;

	while (1) {
		cin >> tmp;
		if (tmp == 0)
			break;
		order.push_back(tmp);
	}
	
	cout << solve(0, 0, 0);


	return 0;
}
