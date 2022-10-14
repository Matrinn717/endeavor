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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dum=new ListNode(0);
        ListNode* cur=new ListNode(0);
        cur=dum;
        while((l1 != nullptr) && (l2 != nullptr) ){
            if(l1->val<l2->val){
                cur->next=l1;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        if(l1!=nullptr){
            cur->next=l2;
            return dum->next;

        }
        else{
            cur->next=l1;
            return dum->next;
        }
    }
};