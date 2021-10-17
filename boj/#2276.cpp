#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

#define MAX 1000001

int note1[MAX];
int note2[MAX];

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, M;

	cin >> T;
	
	while (T--) {

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> note1[i];
		}

		sort(note1, note1 + N);

		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> note2[i];
		}

		for (int i = 0; i < M; i++) {
			int idx = lower_bound(note1, note1 + N, note2[i]) - note1;

			if (idx >= N || note1[idx] != note2[i])
				cout << 0 << "\n";
			else if (note1[idx] == note2[i])
				cout << 1 << "\n";
		}

	}





	return 0;
}
