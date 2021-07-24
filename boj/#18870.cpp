#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


int main() {
	int N, tmp;

	cin >> N;

	vector<int> nums;


	for (int i = 0; i < N; i++) {
		cin >> tmp;
		nums.push_back(tmp);
	}

	vector<int> ans = nums;
	unordered_map<int,int> hash;

	sort(nums.begin(), nums.end());

	int dup = nums[0] - 1;
	int cnt = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (dup < nums[i]) {
			hash[nums[i]] = cnt++;
			dup = nums[i];
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << hash[ans[i]] << " ";
	}
	return 0;
}