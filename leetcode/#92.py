# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseBetween(self, head, left, right):
        """
        :type head: ListNode
        :type left: int
        :type right: int
        :rtype: ListNode
        """
        dummy = ListNode(0, head)
        prev = dummy
        
        for _ in range(left - 1):
            prev = prev.next
            
        cur = prev.next
        
        
        for _ in range(right - left):
            forw = cur.next
            cur.next = forw.next
            forw.next = prev.next
            prev.next = forw
            
        return dummy.next
            
            