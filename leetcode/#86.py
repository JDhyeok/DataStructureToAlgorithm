# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """

        bigger_start, bigger_trav = None, None
        lesser_start, lesser_trav = None, None
        trav = head
        
        while trav != None:
            if trav.val < x:
                if lesser_start == None:
                    lesser_start = trav
                    lesser_trav = trav
                else:
                    lesser_trav.next = trav
                    lesser_trav = lesser_trav.next
            else:
                if bigger_start == None:
                    bigger_start = trav
                    bigger_trav = trav
                else:
                    bigger_trav.next = trav
                    bigger_trav = bigger_trav.next
            trav = trav.next
        
        
        if bigger_start == None:
            return lesser_start
        elif lesser_trav == None:
            return bigger_start
        else:
            bigger_trav.next = None
            lesser_trav.next = bigger_start
            
        return lesser_start