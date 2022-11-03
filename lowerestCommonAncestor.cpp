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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(p->val > q->val){ //保证 p->val < q->val
        TreeNode* tmp = p;
        p = q;
        q = tmp;
       }
       while(root != nullptr){
        if(root->val < p->val) // p,q 都在 root 的右子树中 ：root小于最小值，因此遍历右子树
            root = root->right;// 遍历至右子节点
        else if(root->val > q->val) // p,q 都在 root 的左子树中 ：root大于最大值，则左子树
            root = root->left; // 遍历至左子节点
        else break;
       }
       return root;
    }
    
};