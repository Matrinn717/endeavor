/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
    public:
        vector<int> levelOrder(TreeNode* root){
            vector<int> res;//利用队列的先入先出 res用来打印返回数组类型
            if(!root) return res;

            queue<TreeNode*> q;
            q.push(root);
            while(q.size()){
                TreeNode* node=q.front();
                q.pop();
                res.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            return res;

        }
}