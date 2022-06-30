#include<iostream>
#include<queue>
#include<string>
#include<math.h>
#include<time.h>
#include<algorithm>

using namespace std;

vector<int> arr, nums;

vector<int> check_left(vector<int> nums) {

	vector<int> ret(nums.size());
	
	for (int i = 0;i < nums.size();i++) {

		int cnt = 0;

		for (int j = 0;j < i;j++) {
			if (nums[i] < nums[j]) {
				cnt++;
			}
		}
		ret[nums[i] - 1] = cnt;
	}

	return ret;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	int tmp;
	for (int i = 0;i < N;i++) {
		cin >> tmp;
		arr.push_back(tmp);
		nums.push_back(i + 1);
	}


	do {
		vector<int> v = check_left(nums);
	


		if (v == arr) {
			for (int i = 0;i < nums.size();i++)
				cout << nums[i] << " ";

		}
	} while (next_permutation(nums.begin(), nums.end()));
		
	return 0;
}