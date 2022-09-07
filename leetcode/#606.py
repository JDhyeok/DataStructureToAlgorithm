# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        
        global ret
        ret = ''
        
        def postorder(node):
            global ret
            if node == None:
                return
            
            ret += str(node.val)
            
            if node.right != None or node.left != None:
                ret += '('
            postorder(node.left)
            if node.right != None or node.left != None:
                ret += ')'
                
            if node.right != None:
                ret += '('
            postorder(node.right)
            if node.right != None:
                ret += ')'
            
        postorder(root)
        return ret


# Better Solution

    def tree2str(self, root: Optional[TreeNode]) -> str:
                    
        if(root == None):
            return ""
        
        output: str = str(root.val)
        
        if (root.left != None or root.right != None):
            output += "(" + self.tree2str(root.left) + ")"
            
        if (root.right != None):
            output += "(" + self.tree2str(root.right) + ")"          
        
        return output;    
