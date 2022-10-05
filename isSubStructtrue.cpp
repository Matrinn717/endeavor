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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == null || A == null)
            return false;
        //遍历A中每一个结点，A树中的任一结点包含B就能返回true
        return iscontain(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);

    }

    //包含：以A为根的数是否包含B（必须从A开始）
    bool iscontain(TreeNode* A, TreeNode* B){
        if(B==null)
            return true;
        if(A==null || A->val != B->val)
            return false;
        return iscontain(A->left,B->left) && iscontain(A->right,B->right);
    }
};