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
    bool isSymmetric(TreeNode* root) {
        if(!root) 
            return true;
        else
            return isSymmetric(root->left,root->right);
    }
    bool isSymmetric(TreeNode* left,TreeNode* right){
        // 结束条件1：如果对称两个节点都为空，则返回true
        if(!left && !right)
            return true;
        // 结束条件2：如果单独一个节点为空，另一个节点不为空，又或者是对称节点间的val值不等，则返回false
        if(!left || !right || left->val != right->val)
            return false;
        // 该层符合对称二叉树的要求，开始比较下一层
        return isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
    }
};