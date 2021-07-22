#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<algorithm>

using namespace std;
#pragma warning (disable:4996)

int main() {
	int T, n;
	string str;
	string numStr;
	vector<int> num;
	bool flag = false;
	bool isReverse = false;

	int start, end;

	cin >> T;

	for (int t = 0; t < T; t++) {
		str.clear();
		numStr.clear();

		cin >> str;
		cin >> n;
		cin >> numStr;
		num.clear();

		char ch[1000000];
		strcpy(ch, numStr.c_str());
		char* pch = strtok(ch, "[,]");
		while (pch != NULL) {
			num.push_back(atoi(pch));
			pch = strtok(NULL, "[,]");
		}
		free(pch);
		isReverse = false;

		start = 0; end = num.size() - 1;

		for (int i = 0; i < str.size(); i++) {
			flag = false;

			if (str[i] == 'R') {
				isReverse = !isReverse;
			}
			else if (str[i] == 'D') {
				if (start >= end+1) {
					flag = true;
					break;
				}
				if (isReverse){
					end--;
				}	
				else {
					start++;
				}
			}
			if (flag)
				break;
		}
		if (flag) {
			cout << "error\n";
			continue;
		}

		cout << "[";
		string tmp;
		tmp.clear();
		if (isReverse) {
			for (int i = end; i >= start; i--) {
				tmp += to_string(num[i]);
				if (i == start)
					break;
				tmp += ',';
			}
		}
		else {

			for (int i = start; i <= end; i++) {
				tmp += to_string(num[i]);
				if (i == end)
					break;
				tmp += ',';
			}
		}
		cout << tmp;
		cout << "]\n";
	}
	return 0;
}