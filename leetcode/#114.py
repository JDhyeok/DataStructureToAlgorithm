# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        if root == None:
            return None
        tmp1, tmp2 = None, None
        if root.left != None:
             tmp1 = self.flatten(root.left)
        if root.right != None:
             tmp2 = self.flatten(root.right)
                
        if tmp1 != None:
            root.right = tmp1
            trav = root
            while trav.right != None:
                trav.left = None
                trav = trav.right
            trav.right = tmp2
            trav.left = None
        root.left = None
        
        return root