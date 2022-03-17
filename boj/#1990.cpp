#include<iostream>
#include<queue>
#include<string>
#include<math.h>
#include<time.h>
#include<algorithm>

using namespace std;

#define MAX 10000000

int a, b;
vector<int> palindromes;

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

bool isPalindrome(int n) {
	int origin = n;
	int reversed_n = 0;

	while (n) {
		reversed_n = reversed_n * 10 + n % 10;
		n /= 10;
	}
	
	return reversed_n == origin;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a >> b;


	if (b >= MAX)
		b = MAX;

	for (int i = a; i <= b; i++) {
		if (isPalindrome(i))
			palindromes.push_back(i);
	}

	for (int i = 0; i < palindromes.size(); i++) {
		if (isPrime(palindromes[i]))
			cout << palindromes[i] << "\n";
	}

	cout << -1 << "\n";


	return 0;
}