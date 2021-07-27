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
    
    TreeNode* bst(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return NULL;
        }

        int mid = (end + start) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->right = bst(nums, mid + 1, end);
        root->left = bst(nums, start, mid);

        return root;
    }


    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return bst(nums, 0, nums.size());

    }
};