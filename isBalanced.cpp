/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int left = depth(root->left);
        int right = depth(root->right);
        int dif = abs(left - right);
        if(dif <= 1) return isBalanced(root->left) && isBalanced(root->right);
        return false;
    }
    int depth(TreeNode* root){
        if(!root) return 0;
        
        return 1 + max(depth(root->left), depth(root->right));
    }
    
};