#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int A[51], B[51];

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < N; i++)
		cin >> B[i];

	sort(A, A + N);
	sort(B, B + N, greater<>());
	
	int ans = 0;
	for (int i = 0; i < N; i++)
		ans += (A[i] * B[i]);

	cout << ans;
	return 0;
}
