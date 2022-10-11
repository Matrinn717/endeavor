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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* pre=head, *cur=head;
        int i=1;
        while(i!=k){
            pre=pre->next;
            i++;
        }
        while(pre->next!=nullptr){
            pre=pre->next;
            cur=cur->next;
        }
        return cur;

    }
};