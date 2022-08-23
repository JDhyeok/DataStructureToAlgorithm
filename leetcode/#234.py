# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        
        def check(node):
            if node == None:
                return True
            
            ret = check(node.next) and (self.trav.val == node.val)
            self.trav = self.trav.next
            
            return ret
            
        self.trav = head
        return check(head)