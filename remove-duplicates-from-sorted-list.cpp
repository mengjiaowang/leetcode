class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            if(head == NULL) return NULL;
            ListNode * p1 = head, *p2 = p1->next;
            while(p2 != NULL){
                if(p1->val == p2->val){
                    p1->next = p2->next;
                    delete p2;
                    p2 = p1->next;
                }else{
                    p1 = p1->next;
                    p2 = p2->next;
                }
            }
            return head;
        }
};
