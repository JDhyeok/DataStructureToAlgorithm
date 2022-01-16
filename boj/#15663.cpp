#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
#include<unordered_map>

using namespace std;

int N, M, mask = 0;
bool visited[9];
vector<int> inputs;

void combination(vector<int>& nums) {

	if (nums.size() == M) {
		for (int i = 0; i < M; i++)
			cout << nums[i] << " ";
		cout << "\n";
		return;
	}

	int prev_num = 0;
	for (int i = 0; i < inputs.size(); i++) {
		if (visited[i] || prev_num == inputs[i])
			continue;

		nums.push_back(inputs[i]);
		visited[i] = true;
		prev_num = inputs[i];
		combination(nums);
		nums.pop_back();
		visited[i] = false;
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill_n(visited, 9, false);

	cin >> N >> M;
	
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		inputs.push_back(tmp);
	}

	sort(inputs.begin(), inputs.end());

	vector<int> nums;
	combination(nums);

	return 0;
}