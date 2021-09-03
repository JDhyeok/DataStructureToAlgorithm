#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

#define MAX 100001

int N, M;
int A[MAX];
bool ans = false;

void find(int n, int l, int r) {
	
	if (ans || r <= l)
		return;

	int mid = (l + r) / 2;

	if (A[mid] < n) {
		find(n, mid + 1, r);
	}
	else if (A[mid] > n) {
		find(n, l, mid);
	}
	if (A[mid] == n) {
		ans = true;
		return;
	}
}

int main() {

	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	sort(A, A + N);

	int tmp;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		ans = false;
		find(tmp, 0 , N);
		cout << ans << "\n";
	}

	return 0;
}
