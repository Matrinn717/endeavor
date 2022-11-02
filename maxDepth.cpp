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
    int maxDepth(TreeNode* root) {//dfs
        if(root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

class Solution{
    int count = 0;//bfs
    public:
        int maxDepth(TreeNode* root){
            if(root == nullptr) return 0;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                for(int i = q.size(); i; i--){
                    auto node = q.front();//auto关键字为变量自动选择匹配的类型
                    q.pop();
                    if(node->left != nullptr) q.push(node->left);
                    if(node->right != nullptr) q.push(node->right);
                }
                count++;
            }
            return count;
        }
}