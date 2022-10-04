class Solution{
    public:
        vector<vector<int>> levelOrder(TreeNode* root){
            queue<TreeNode*> q;
            vector<vector<int>> ans;
            if(!root) return ans;

            q.push(root);
            while(!q.empty()){
                vector<int> temp;
                for(int i= q.size();i>0;i--){
                    TreeNode* node= q.front();
                    q.pop();
                    temp.push_back(node->val);
                    if(node->left)
                        q.push(node->left);
                    if(node->right)
                        q.push(node->right);
                }
                ans.push_back(temp);
            }
            return ans;
        }
}