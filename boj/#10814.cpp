#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
#include<unordered_map>

using namespace std;

int N;

bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, string>> list;

	cin >> N;

	int tmp;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> tmp >> str;
		list.push_back({ tmp, str });
	}

	stable_sort(list.begin(), list.end(), cmp);
	
	for (auto l : list)
		cout << l.first << " " << l.second << "\n";

	return 0;
}