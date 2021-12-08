/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int ans = 0;
    
    int tilt(TreeNode* root){
        if(!root)
            return 0;
        
        int val = root->val;
        
        int rchild = tilt(root->right);
        int lchild = tilt(root->left);
        
        ans += abs(rchild - lchild);
        
        return val + rchild + lchild;
    }
    
    int findTilt(TreeNode* root) {
        tilt(root);
        return ans;
    }
};