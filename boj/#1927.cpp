#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int N, cnt = 0;
int minHeap[100001];

int pop() {
	int ret = minHeap[1];
	minHeap[1] = minHeap[cnt--];
	minHeap[cnt + 1] = 0;

	int tmp = 1;

	while (tmp*2+1 <= cnt) {
		if (minHeap[tmp] > minHeap[tmp * 2] || minHeap[tmp] > minHeap[tmp * 2 + 1]) {
			if (minHeap[tmp * 2] > minHeap[tmp * 2 + 1]) {
				swap(minHeap[tmp * 2 + 1], minHeap[tmp]);
				tmp = tmp * 2 + 1;
			}
			else if (minHeap[tmp * 2] <= minHeap[tmp * 2 + 1]) {
				swap(minHeap[tmp * 2], minHeap[tmp]);
				tmp *= 2;
			}
			else
				break;
		}
		else
			break;
	}
	if (tmp * 2 <= cnt && minHeap[tmp] > minHeap[tmp * 2])
		swap(minHeap[tmp], minHeap[tmp * 2]);

	return ret;
}

void push(int n) {
	minHeap[++cnt] = n;

	int tmp = cnt;
	while (minHeap[tmp] < minHeap[tmp / 2] && tmp >= 1) {
		swap(minHeap[tmp], minHeap[tmp / 2]);
		tmp /= 2;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	minHeap[0] = -987654321;
	cin >> N;

	int tmp, num;

	for (int i = 0; i < N; i++) {

		cin >> tmp;

		if (tmp == 0) {
			if (cnt == 0)
				cout << 0 << "\n";
			else
				cout << pop() << "\n";
		}
		else {
			push(tmp);
		}
	}
	
	return 0;
}
