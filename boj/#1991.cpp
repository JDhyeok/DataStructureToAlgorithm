#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

vector<pair<char, bool>> adList[26];

void preorder(char root) {
	int rootIdx = root - 'A';

	cout << root;
	for (int i = 0; i < adList[rootIdx].size(); i++)
		preorder(adList[rootIdx][i].first);

	return;
}

void inorder(char root) {
	int rootIdx = root - 'A';

	if (adList[rootIdx].size() == 1) {
		if (adList[rootIdx][0].second) {
			inorder(adList[rootIdx][0].first);
			cout << root;
		}
		else if(adList[rootIdx][0].second == false)
		{
			cout << root;
			inorder(adList[rootIdx][0].first);
		}
	}
	else if (adList[rootIdx].size() == 2) {
		inorder(adList[rootIdx][0].first);
		cout << root;
		inorder(adList[rootIdx][1].first);
	}
	else
		cout << root;
	return;
}

void postorder(char root) {
	int rootIdx = root - 'A';

	for (int i = 0; i < adList[rootIdx].size(); i++)
		postorder(adList[rootIdx][i].first);

	cout << root;
	
	return;
}

int main() {

	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0);


	int N;
	cin >> N;

	char root, lchild, rchild;

	for (int i = 0; i < N; i++) {
		cin >> root >> lchild >> rchild;
		if(lchild != '.')
			adList[root - 'A'].push_back({ lchild, true });
		if (rchild != '.')
			adList[root - 'A'].push_back({ rchild , false });
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');

	return 0;
}
