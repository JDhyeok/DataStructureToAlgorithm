# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        global num_list
        num_list, ans = [], 987654321

        def inorder(node):
            if node == None:
                return
            global num_list
            inorder(node.left)
            num_list.append(node.val)
            inorder(node.right)
        
        inorder(root)
        
        for i in range(len(num_list) - 1):
            ans = min(ans, num_list[i + 1] - num_list[i])

        return ans


# Better Space Complexity Solution
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        global ans
        ans = 987654321
        
        global prevNode
        prevNode = None

        def inorder(node):
            if node == None:
                return
            global ans
            global prevNode

            inorder(node.left)
            if prevNode != None:
                ans = min(ans, node.val - prevNode.val)
            prevNode = node
            inorder(node.right)
        
        inorder(root)
       
        return ans