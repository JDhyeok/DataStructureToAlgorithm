#include<iostream>
#include<vector>

using namespace std;

int N, M;
vector<int> v;

void dfs(int start, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}
	
	for (int i = start + 1; i <= N; i++) {
		v.push_back(i);
		dfs(i, cnt + 1);
		v.pop_back();
	}
	
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		if (N - i + 1< M)
			break;
		v.push_back(i);
		dfs(i, 1);
		v.pop_back();
	}


	return 0;
}
