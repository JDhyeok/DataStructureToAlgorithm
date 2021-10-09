#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int N;
vector<pair<int, int>> flower;

int calcDay(int m, int d) {
	int ret = 0;
	switch (m) {
	case 1:
		ret += 0;
		break;
	case 2:
		ret += 31;
		break;
	case 3:
		ret += 59;
		break;
	case 4:
		ret += 90;
		break;
	case 5:
		ret += 120;
		break;
	case 6:
		ret += 151;
		break;
	case 7:
		ret += 181;
		break;
	case 8:
		ret += 212;
		break;
	case 9:
		ret += 243;
		break;
	case 10:
		ret += 273;
		break;
	case 11:
		ret += 304;
		break;
	case 12:
		ret += 334;
		break;
	}
	ret += d;
	return ret;
}

bool cmp(pair<int,int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

bool comp(const pair<int, int> a, const pair<int, int> b) {
	return a.first < b.first;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int sm, sd, em, ed, endDay = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> sm >> sd >> em >> ed;

		int s = calcDay(sm, sd);
		int e = calcDay(em, ed);
		if(s == e)
			continue;

		endDay = max(endDay, e);

		flower.push_back({ s, e });
	}

	sort(flower.begin(), flower.end(), cmp);

	int strt = 60, end = 335;
	int ans = 0, pre = 0;

	if (endDay < end) {
		cout << 0;
		return 0;
	}

	//cout << endl;
	//for (int i = 0; i < flower.size(); i++)
	//	cout << flower[i].first << " " << flower[i].second << "\n";

	while (strt < end) {

		int idx = upper_bound(flower.begin(), flower.end(), make_pair(strt, 0), comp) - flower.begin();
		int nextEnd = 0;

		for (int i = 0; i < idx; i++) {
			if (pre <= flower[i].first) {
				nextEnd = max(nextEnd, flower[i].second);
			}
		}

		if (nextEnd == 0) {
			ans = 0;
			break;
		}

		ans++;
		pre = strt;
		strt = nextEnd;
		
	}

	cout << ans;

	return 0;
}