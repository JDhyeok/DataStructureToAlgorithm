#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string exp;
	string ans;

	vector<char> stack;

	cin >> exp;

	for (int i = 0; i < exp.size(); i++) {
		// 문자일 때
		if ('A' <= exp[i] && exp[i] <= 'Z') {
			ans += exp[i];
		}
		// 우선순위 연산자가 닫혔을 때는 열림 연산자 나올 때 까지 빼기
		else if (exp[i] == ')') {
			while (stack.back() != '(') {
				ans += stack.back();
				stack.pop_back();
			}
			stack.pop_back();
		}
		// 그냥 연산자라면
		else {
			if (!stack.empty() && exp[i] == '+' || exp[i] == '-') {
				while (!stack.empty() && stack.back() != '(') {
					ans += stack.back();
					stack.pop_back();
				}
			}
			else if (!stack.empty() && exp[i] == '*' || exp[i] == '/') {
				while (!stack.empty() && stack.back() != '(' && stack.back() != '+' && stack.back() != '-') {
					ans += stack.back();
					stack.pop_back();
				}
			}

			stack.push_back(exp[i]);
		}
		
	}
	// 모든 식이 끝났을 때
	while (!stack.empty()) {
		if (stack.back() != '(')
			ans += stack.back();
		stack.pop_back();
	}


	cout << ans << "\n";

	return 0;
}