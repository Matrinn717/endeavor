/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution{
    public:
    Node* copyRandomList(Node* head){
        if(head == nullptr) return nullptr;
        Node* cur=head;
        unordered_map<Node*,Node*> map;
        while(cur!=nullptr){
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while(cur != nullptr){
            map[cur]->next = map[cur->next];
            map[cur]->random= map[cur->random];
            cur= cur->next;
        }
        return map[head];
     }


     class Solution{
        public:
        Node* copyRandomList(Node* head){
            if(head == nullptr) return nullptr;
            Node* cur=head;
            //复制各节点，并创建拼接链表
            while(cur != nullptr){
                Node*tmp= new Node(cur->val);
                tmp->next= cur->next;
                cur->next=tmp;
                cur= tmp->next;
            }
            //构建各新节点的random指向
            cur=head;
            while(cur!=nullptr){
                if(cur->random != nullptr)
                    cur->next->random=cur->random->next;
                cur=cur->next->next;
            }
            //拆分两链表
            cur=head->next;
            Node* pre=head,*res=head->next;
            while(cur->next != nullptr){
                pre->next=pre->next->next;
                cur->next= cur->next->next;
                pre= pre->next;
                cur= cur->next;
            }
            pre->next= nullptr;
            return res;
        }
     }
}



