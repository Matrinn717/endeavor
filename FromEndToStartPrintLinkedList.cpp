/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> st;
        while(head){
            st.push(head->val);
            head = head->next;
        }

        vector<int> vec;//返回的是数组类型
        while(!st.empty()){
            vec.push_back(st.top());
            st.pop();
        }
        return vec;
    }
};