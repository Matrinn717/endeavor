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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA, *B=headB;
        while(A != B){
            A = A!= nullptr ? A->next : headB;
            B = B !=nullptr ? B->next : headA;
        }
        return A;
    }
};
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//     struct ListNode* p1 = headA;
    // struct ListNode* p2 = headB;
    // while (p1 != p2) {
    //     if (p1 == NULL) {
    //         p1 = headB;
    //     }else {
    //         p1 = p1->next;
    //     }
    //     if (p2 == NULL) {
    //         p2 = headA;
    //     }else {
    //         p2 = p2->next;
    //     }
    // }
    // return p1;
//         
//     }
// };

