#include<iostream>
using namespace std;

class SLLNode {
public:
	int val;
	SLLNode* next;

	SLLNode() : val(0), next(nullptr) {}
	SLLNode(int n) : val(n), next(nullptr) {}
	SLLNode(int n, SLLNode* ptr) :val(n), next(ptr) {}

};

class SLList {
private:
	SLLNode* head, * tail;

public:
	SLList() {
		head = nullptr;
		tail = nullptr;
	}
	~SLList();

	bool isEmpty() {
		return head == nullptr;
	}
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead();
	int deleteFromTail();
	void deleteNode(int);
};

SLList::~SLList() {
	for (SLLNode* p; !isEmpty(); ) {
		p = head->next;
		delete head;
		head = p;
	}
}

void SLList::addToHead(int num) {
	head = new SLLNode(num, head);
	if (tail == nullptr)
		tail = head;
}

void SLList::addToTail(int num) {
	if (tail != nullptr) {
		SLLNode* tmp = new SLLNode(num);
		tail->next = tmp;
		tmp = tail;
	}
	else {
		head = new SLLNode(num);
		tail = head;
	}
}


int SLList::deleteFromHead() {
	int deleted = head->val;

	if (head->next == nullptr) {
		head = nullptr;
	}
	else {
		SLLNode* tmp = head;
		head = head->next;
		delete tmp;
	}
	return deleted;
}

int SLList::deleteFromTail() {
	int deleted = head->val;
	SLLNode* travel = head;
	
	if (head == tail) {
		delete tail;
		head = nullptr;
	}
	else {

		for (travel; travel->next != tail; travel = travel->next);
		delete tail;
		tail = travel;
		tail->next = nullptr;
	}
	return deleted;
}

void SLList::deleteNode(int num) {

	if (head->val == num) {
		SLLNode* tmp = head;
		head = head->next;
		delete tmp;
	}
	else {
		SLLNode* travel = head;
		for (travel; travel->next->val == num; travel = travel->next);
		if (travel->next == tail) {
			delete tail;
			tail = travel;
			tail->next = nullptr;
		}
		else {
			SLLNode* tmp = travel->next;
			travel->next = travel->next->next;
			delete tmp;
		}
	}
}