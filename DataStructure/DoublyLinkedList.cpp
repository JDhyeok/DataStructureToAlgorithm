#include<iostream>
using namespace std;

class DLLNode {
public:
	int val;
	DLLNode* left;
	DLLNode* right;

	DLLNode() : val(0), left(nullptr), right(nullptr) {}
	DLLNode(int n) : val(n), left(nullptr), right(nullptr) {}
	DLLNode(int n, DLLNode* l, DLLNode* r) :val(n), left(l), right(r) {}
};

