#include<iostream>

using namespace std;


int main() {
	long long len[101];
	len[1] = len[2] = len[3] = 1;
	len[4] = len[5] = 2;

	int T, N;

	for (int i = 6; i <= 100; i++) {
		len[i] = len[i - 1] + len[i - 5];
	}

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;
		cout << len[N] << "\n";
	}

}