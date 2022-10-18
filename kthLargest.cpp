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
    int kthLargest(TreeNode* root, int k) {
        
        dfs(root,k);
        return ans;
    }

    void dfs(TreeNode* root, int &k){
        //k要加引用符号
        if(root == nullptr) return ;
        if(root->right) dfs(root->right,k);
        
        if(--k == 0){
            ans = root->val;
            return ;
        }
        if(root->left) dfs(root->left,k);
    }
private:
    int ans;
};


class Solution{
    public:
        int kthLargest(TreeNode* root, int k){
            stack<TreeNode*> stk;
            TreeNode* cur = root;
            while(cur != nullptr || !stk.empty()){
                if(cur != nullptr){
                    stk.push(cur);
                    cur = cur->right;
                }
                else{
                    cur = stk.top();
                    stk.pop();
                    if(--k == 0) return cur->val;
                    cur = cur->left;
                }
            }
            return -1;
        }
}