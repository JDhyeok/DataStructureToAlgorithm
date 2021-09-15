#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


unsigned long long pow(unsigned long long A, unsigned  long long B, unsigned long long C) {
	if (B == 0)
		return 1;
	if (B == 1)
		return A;

	if (B % 2 > 0)
		return pow(A, B - 1,C) * A;

	unsigned long long tmp = pow(A, B / 2, C) % C;

	return (tmp * tmp) % C;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	unsigned long long A, B, C;

	cin >> A >> B >> C;

	cout << pow(A, B, C) % C << "\n";
	
	return 0;
}
