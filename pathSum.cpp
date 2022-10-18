/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(TreeNode* root, int target){
        if(root == nullptr)
            return ;
        path.emplace_back(root->val);
        target -= root->val;
        if(root->left == nullptr && root->right == nullptr && target == 0){
            ret.emplace_back(path);
        }
        dfs(root->left, target);
        dfs(root->right, target);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return ret;
    }
};


class Solution{
    public:
        vector<vector<int>> ret;
        unordered_map<TreeNode*, TreeNode*> parent;
        void getPath(TreeNode* node){
            vector<int> tmp;
            while(node != nullptr){
                tmp.emplace_back(node->val);
                node = parent[node];
            }
            reverse(tmp.begin(), tmp.end());
            ret.emplace_back(tmp);
        }

        vector<vector<int>> pathSum(TreeNode* root, int target){
            if(root == nullptr)
                return ret;
            queue<TreeNode*> que_node;
            queue<int> que_sum;
            que_node.emplace(root);
            que_sum.emplace(0);

            while(!que_node.empty()){
                TreeNode *node=que_node.front();
                que_node.pop();
                int rec = que_sum.front() + node->val;
                que_sum.pop();

                if(node->left == nullptr && node->right == nullptr){
                    if(rec == target){
                        getPath(node);
                    }
                }
                else{
                    if(node->left != nullptr){
                        parent[node->left] = node;
                        que_node.emplce_back(node);
                        que_sum.emplace_back(rec);
                    }
                    if(node->right != nullptr){
                        parent[node->right] = node;
                        que_node.emplce_back(node);
                        que_sum.emplace_back(rec);
                    }
                }
            }
            return ret;
        }
};