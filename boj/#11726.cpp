#include<iostream>


using namespace std;


int main() {
	
	int N;
	long arr[1001] = { 0 ,1 ,2 ,};

	for (int i = 3; i < 1001; i++)
		arr[i] = (arr[i - 1] + arr[i - 2])%10007;

	cin >> N;
	cout << arr[N];

	return 0;
}