#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int N;
vector<pair<int, int>> vec;

bool cmp(pair<int,int> a, pair<int,int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		vec.push_back({ a, b });
	}

	sort(vec.begin(), vec.end(), cmp);
	
	int ans = 0;
	int endTime = 0;

	for (int i = 0; i < N; i++) {
		if (endTime <= vec[i].first) {
			endTime = vec[i].second;
			ans++;
		}
	}

	cout << ans << "\n";


	return 0;
}
