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
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return null;

        TreeNode* leftRoot = mirrorTree(root->right);
        TreeNode* rightRoot = mirrorTree(root->left);
        root->left = leftRoot;
        root->right = rightRoot;
        return root;
    }

};

// TreeNode* left = mirrorTree(root->left);
// TreeNode* right = mirrorTree(root->right);
// root->left = right;
// root->right = left;
