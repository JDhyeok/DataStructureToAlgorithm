#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

#define MAX 1000001

int N, A[MAX];
vector<int> stacks;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	vector<int> ans;
	for (int i = N - 1; i >= 0; i--) {
		if (stacks.empty()) {
			ans.push_back(-1);
			stacks.push_back(A[i]);
			continue;
		}

		if (stacks.back() > A[i]) {
			ans.push_back(stacks.back());
			stacks.push_back(A[i]);
		}
		else {
			while (!stacks.empty() && stacks.back() <= A[i])
				stacks.pop_back();

			if (stacks.empty())
				ans.push_back(-1);
			else 
				ans.push_back(stacks.back());
			stacks.push_back(A[i]);

		}
	}

	for (int i = N - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}

	return 0;
}
