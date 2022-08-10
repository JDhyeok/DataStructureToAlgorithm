# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def create_bst(self, l, r, nums):
        if l >= r:
            return None
        
        mid = (l + r) // 2
        
        node = TreeNode(nums[mid])
        
        node.left = self.create_bst(l, mid, nums)
        node.right = self.create_bst(mid + 1, r, nums)
        
        return node
        
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        
        return self.create_bst(0, len(nums), nums)