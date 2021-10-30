#include<iostream>
#include<vector>

using namespace std;

int N;
string str;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	vector<char> stacks;
	int ans = 0;

	while (N--) {
		cin >> str;
		stacks.clear();
		for (int i = 0; i < str.size(); i++) {
			if (stacks.empty() || stacks.back() != str[i]) {
				stacks.push_back(str[i]);
			}
			else if (stacks.back() == str[i]) {
				stacks.pop_back();
			}
		}
		if (stacks.empty())
			ans++;
	}

	cout << ans;

	return 0;
}
