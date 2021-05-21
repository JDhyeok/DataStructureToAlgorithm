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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        
        if(root == NULL)
            return {};
        
        vector<int> tmp;
        vector<vector<int>> answer;
        
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            
            tmp.clear();
            for(int i = 0; i < n; i++){
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                
                tmp.push_back(q.front()->val);
                q.pop();
                
            }
            
            answer.push_back(tmp);
        }
        return answer;
    }
};