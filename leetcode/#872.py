# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root):
        if root == None:
            return []
        
        if root.left == None and root.right == None:
            return [root.val]

        return self.dfs(root.left) + self.dfs(root.right)
        
        
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        
        return self.dfs(root1) == self.dfs(root2)
        