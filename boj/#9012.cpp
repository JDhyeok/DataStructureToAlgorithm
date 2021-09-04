#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

bool check(string str) {
	int tmp = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')
			tmp++;
		else if(str[i] == ')') {
			if (tmp <= 0)
				return false;
			tmp--;
		}		
	}

	return !tmp;
}

int main() {

	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	int N;
	string str;
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (check(str))
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	
	return 0;
}
