#include<iostream>

using namespace std;

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(TreeNode* l, TreeNode* r, int val) :left(l), right(r), val(val) {}
};

TreeNode* root;

void insert(int val) {
	TreeNode* node = new TreeNode(NULL, NULL, val);

	if (root == NULL) {
		root = node;
		return;
	}

	TreeNode* trav = root;
	TreeNode* pre;
	while (trav) {
		pre = trav;
		if (trav->val < val) {
			trav = trav->right;
		}
		else {
			trav = trav->left;
		}
	}
	if (pre->val < val) {
		pre->right = node;
	}
	else{
		pre->left = node;
	}
	return;
}

void postorder(TreeNode* node) {
	if (!node)
		return;
	postorder(node->left);
	postorder(node->right);
	cout << node->val << "\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tmp;

	while (cin >> tmp) {

		insert(tmp);
	}
	
	postorder(root);

	return 0;
}