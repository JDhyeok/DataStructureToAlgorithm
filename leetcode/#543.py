# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.ans = 0
        
    def traverse(self, root):
        if root.left == None and root.right == None:
            return 1
        
        l, r = 0, 0
        
        if root.left != None:
            l = self.traverse(root.left)
        if root.right != None:
            r = self.traverse(root.right)
            
        self.ans = max(self.ans, l + r)
        return max(l, r) + 1
    
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """   
        self.traverse(root)
        
        return self.ans