#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int N, ans = 0;

bool isShom(string str1, string str2) {

	int bit = 0;
	unordered_map<char, char> hashs;

	if (str1.size() != str2.size())
		return false;

	for (int i = 0; i < str1.size(); i++) {
		if (hashs[str1[i]] == NULL) {
			if ((bit & (1 << (str2[i] - 'a'))) > 0)
				return false;
			hashs[str1[i]] = str2[i];
			bit = bit | (1 << (str2[i] - 'a'));
		}
		else {
			if (hashs[str1[i]] != str2[i])
				return false;
		}
	}

	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;

	string tmp;
	vector<string> str;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		str.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (isShom(str[i], str[j]))
				ans++;
		}
	}

	cout << ans;

	return 0;
}