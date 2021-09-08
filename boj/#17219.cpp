#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

string url, pw;
unordered_map<string, string> hashs;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> url >> pw;
		hashs[url] = pw;
	}

	for (int i = 0; i < M; i++) {
		cin >> url;
		cout << hashs[url] << "\n";
	}

	return 0;
}
