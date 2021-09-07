/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* ret;
    ListNode* reverse(ListNode* node) {

        if (!node->next) {
            ret = node;
            return node;
        }

        ListNode* tmp = nullptr;

        tmp = reverse(node->next);
        tmp->next = node;


        return node;
    }

    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
            
        reverse(head)->next = nullptr;

        return ret;
    }
};


// iteration
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* n;
        while(cur!=NULL){
            n=cur->next;
            cur->next=prev;
            prev=cur;
            cur=n;
        }
        return prev;
    }
};