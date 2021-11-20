#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

int nums[10];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill_n(nums, 10, 0);

	char tmp;
	
	while (1) {
		cin.get(tmp);
		if (tmp == '\n')
			break;

		nums[tmp - '0']++;
	}
	
	for (int i = 9; i >= 0; i--) {
		while (nums[i]) {
			cout << i;
			nums[i]--;
		}
	}

	return 0;
}
