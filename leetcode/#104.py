# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        
        global ans
        ans = 0

        def inorder(node, depth):
            if node != None:
                global ans
                ans = max(ans, depth)
                inorder(node.left, depth + 1)
                inorder(node.right, depth + 1)

        inorder(root, 1)

        return ans
        