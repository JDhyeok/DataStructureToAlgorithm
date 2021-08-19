#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>

using namespace std;

// A -> B 로 가는 코드
#define MAX 1000000000

long long A, B;

long long bfs(long long, long long);

int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B;

	cout << bfs(A, B) << "\n";

	return 0;
}

long long bfs(long long A, long long B) {

	if (A == B)
		return 0;
	if (A > MAX || B > MAX || A < 0 || B < 0)
		return -1;

	queue<pair<long, long>> q;
	q.push(make_pair(A,1));


	while (!q.empty()) {
		long long cur = q.front().first;
		long long curCnt = q.front().second;
		q.pop();

		long long mul = cur * 2;
		if (mul == B)
			return curCnt + 1;

		if (mul <= MAX && mul > 0 && mul < B) {
			q.push(make_pair(mul, curCnt + 1));
		}

		long long add = cur * 10 + 1;
		if (add == B)
			return curCnt + 1;

		else if(add <= MAX && add > 0 && add < B) {
			q.push(make_pair(add, curCnt + 1));
		}

		
	}
	return -1;
}

// B -> A 로 가는 코드
// 메모리상으로도 더 나은 코드

int A, B;

int main() {
	cin >> A >> B;

	int cnt = 0;
	while (1) {
		if (A > B) {
			cout << -1 << '\n';
			break;
		}
		if (A == B) {
			cout << cnt + 1 << '\n';
			break;
		}

		if (B % 10 == 1) {
			B /= 10;
		}
		else if(B % 2 == 0){
			B /= 2;
		}
		else {
			cout << -1 << '\n';
			break;
		}
		cnt++;
	}
	return 0;
}