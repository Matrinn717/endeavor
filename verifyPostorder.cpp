class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verifyOrder(postorder, 0, postorder.size() - 1);
    }
    bool verifyOrder(vector<int> & postorder, int l, int r){
        if(l >= r) return true;  //子树节点个数小于等于1
        int i;
        for(i = r; i >= l; i--){
            if(postorder[i] < postorder[r]) break;//找到第一个比跟节点小的
        }
        for(int j = i; j >= l; j--){
            if(postorder[j] > postorder[r]) return false;//左子树中如果有比根节点大的就返回false
        }
        return verifyOrder(postorder, l, i) && verifyOrder(postorder, i + 1, r - 1);
    }    //
};