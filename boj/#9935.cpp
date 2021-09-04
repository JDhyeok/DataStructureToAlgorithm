#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


int main() {

	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	string str;
	string bomb;
	string ret;

	cin >> str;
	cin >> bomb;

	int last = bomb.size() - 1;

	for (int i = 0; i < str.size(); i++) {

		ret.push_back(str[i]);

		if (ret.back() == bomb[last]) {
			if (ret.size() >= bomb.size() && ret.substr(ret.size() - bomb.size(), bomb.size()) == bomb) {
				for (int w = 0; w < bomb.size(); w++)
					ret.pop_back();
			}
		}
	}


	if (ret.empty())
		cout << "FRULA";
	else
		cout << ret;

	return 0;
}
