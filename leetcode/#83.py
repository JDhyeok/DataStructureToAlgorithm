# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        unique, trav = head, head

        while unique != None:
            while trav != None and unique.val == trav.val:
                trav = trav.next
            unique.next = trav
            unique = trav

        return head