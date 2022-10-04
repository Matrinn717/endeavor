class Solution{
    public:
        vector<vector<int>> levelOrder(TreeNode* root){
          vector<vector<int>> ans;
          if(!root) return ans;

          queue<TreeNode*> q;
          q.push(root);
          int count(0);
          while(!q.empty()){
            vector<int> tt;
            for(int i=q.size();i>0;i--){
                TreeNode* node=q.front();
                q.pop();
                tt.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }
            if(count++%2==1){
                reverse(tt.begin(),tt.end());
                
            }
            ans.push_back(tt);
          }
          return ans;
        }
}