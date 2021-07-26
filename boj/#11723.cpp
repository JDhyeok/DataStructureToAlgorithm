#include<iostream>

using namespace std;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string op;
	int n;
	int mask = 0;

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {

		cin >> op;
		if (op == "all") {
			mask = 0xFFFFFFFF;
			continue;
		}
		else if (op == "empty") {
			mask &= 0;
			continue;
		}

		cin >> n;
		if (op == "add") {
			mask |= 1 << n;
		}
		else if (op == "remove") {
			mask &= (0xFFFFFFFF ^ 1 << n);
		}
		else if (op == "toggle") {
			mask ^= 1 << n;
		}
		else if (op == "check") {
			if (mask & (1 << n))
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		
	}
	
	return 0;
}