# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        global nums
        global dup
        
        nums = []
        dup = False
        
        def inorder(node):
            global nums
            global dup
            if node == None:
                return
            inorder(node.left)
            nums.append(node.val)
            inorder(node.right)
              
        inorder(root)
        if len(list(set(nums))) != len(nums):
            return False
        
        return True if nums == sorted(nums) else False