#include<iostream>
#include<queue>
#include<string>
#include<math.h>
#include<time.h>
#include<algorithm>

using namespace std;



int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	
	cin >> N;

	queue<int> q;

	for (int i = 1; i <= N;i++) {
		q.push(i);
	}

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();

		if (!q.empty()) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
	}
		
	return 0;
}