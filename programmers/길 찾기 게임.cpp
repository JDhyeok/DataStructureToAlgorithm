#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode {
    int val, x, y;
    TreeNode* left;
    TreeNode* right;   
    TreeNode(int val,int x,int y) : val(val), x(x), y(y), left(NULL), right(NULL) {}
};



bool cmp(TreeNode& a, TreeNode& b){
    if(a.y == b.y)
        return a.x < b.x;
    return a.y > b.y;
}

void insertNode(TreeNode* parent, TreeNode* child){
    if(parent->x < child->x){
        if(parent->right == NULL)
            parent->right = child;
        else
            insertNode(parent->right, child);
    }
    else{
        if(parent->left == NULL)
            parent->left =child;
        else
            insertNode(parent->left, child);
    }
}

void preorder(TreeNode* root, vector<int>& tmp){
    if(root){
        tmp.push_back(root->val);
        preorder(root->left, tmp);
        preorder(root->right, tmp);
    }
}

void postorder(TreeNode* root, vector<int>& tmp){
    if(root){
        postorder(root->left, tmp);
        postorder(root->right, tmp);
        tmp.push_back(root->val);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<TreeNode> nodes;
    
    
    for(int i = 0; i<nodeinfo.size(); i++){
        nodes.push_back(TreeNode(i+1, nodeinfo[i][0], nodeinfo[i][1]));
    }
    
    sort(nodes.begin(), nodes.end(), cmp);
    
    
    TreeNode* root = &nodes[0];
    for(int i = 1; i < nodes.size(); i++){
        insertNode(root, &nodes[i]);
    }


    vector<int> tmp;
    
    preorder(root, tmp);
    answer.push_back(tmp);
    tmp.clear();
    
    postorder(root, tmp);    
    answer.push_back(tmp);
    
    
    return answer;
}