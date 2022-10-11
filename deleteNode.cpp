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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* pre=head, *cur=pre->next;
        if(head->val == val) return head->next;
        while(cur!=nullptr && cur->val != val){
            pre=cur;
            cur=cur->next;
        }
        if(cur != nullptr) pre->next=cur->next;
        return head;
    }
    
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
       ListNode *pre=head;
       if(head->val == val) return head->next;
       while(pre!=nullptr){
        ListNode* tmp= pre->next;
        if(tmp!=nullptr && tmp->val == val) pre->next=tmp->next;
        else pre=pre->next;
       }
       return head;
    }
    
};