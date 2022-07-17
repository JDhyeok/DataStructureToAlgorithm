# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 42ms / 20.4MB
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None:
            return False
        
        end_point = 10**5 + 1
        while head.next != None and head.val != end_point:
            if head.val == end_point:
                return True
            head.val = end_point
            head = head.next
            
        return True if head.val == end_point else False

# 54ms / 20.5MB
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None:
            return False
        
        p1 = head
        p2 = head
        
        while p1 and p1.next != None:
            p1 = p1.next.next
            p2 = p2.next
            if p1 == p2:
                return True
            
        return False