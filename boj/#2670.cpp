#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

// 문제좀 꼼꼼히 읽자
using namespace std;

int N;
unordered_map<char, int> hashs;
unordered_map<char, int> tmp;

int main() {

	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);

	cin >> N;

	string first;
	string str;

	cin >> first;

	for (int i = 0; i < first.size(); i++)
		first[i] = toupper(first[i]);

	// 첫 번째 글자 알파벳 등장 수 대로 ++
	for (int i = 0; i < first.size(); i++)
		hashs[first[i]]++;

	int cnt = 0;
	int diff = 0;

	for (int w = 0; w< N-1; w++) {

		// 첫 번째 이후 단어 입력
		cin >> str;

		int n1 = first.size();
		int n2 = str.size();

		if (abs(n1 - n2) >= 2) {
			continue;
		}

		for (int i = 0; i < str.size(); i++)
			str[i] = toupper(str[i]);

		// 초기화
		tmp.clear();
		diff = 0;

		// 입력 글자에 대한 알파벳 등장 수 대로 ++
		for (int i = 0; i < str.size(); i++)
			tmp[str[i]]++;

		// 첫 번째와 다르다면 다른 만큼 diff에 누적 저장
		for (int i = 0; i <= 26; i++) {
			diff += abs(hashs['A' + i] - tmp['A' + i]);
		}



		// 막약 누적된 점이 1 이하이면 비슷한 단어이므로 cnt++
		if (diff <= 2) {
			//cout << "\n\n" << str << "\n\n";
			cnt++;
			continue;
		}


	}
	cout << cnt << "\n";

	return 0;
}
