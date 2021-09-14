#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string tmp;
	unordered_map<string, int> hashs;
	vector<string> dict;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		hashs[tmp]++;
	}

	for (int j = 0; j < M; j++) {
		cin >> tmp;
		hashs[tmp]++;
		if (hashs[tmp] >= 2)
			dict.push_back(tmp);
	}

	sort(dict.begin(), dict.end());

	cout << dict.size() << "\n";
	for (auto w : dict)
		cout << w << "\n";

	return 0;
}