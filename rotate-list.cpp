class Solution {
    public:
        ListNode *rotateRight(ListNode *head, int k) {
            if(head == NULL) return NULL;
            ListNode *p1 = head, *p2 = head;
            while(k--){
                p1 = p1->next; if(p1 == NULL) p1 = head;
            }
            if(p1 == NULL) return head;
            while(p1->next != NULL){
                p1 = p1->next;
                p2 = p2->next;
            }
            p1->next = head;
            p1 = p2->next;
            p2->next = NULL;
            return p1;
        }
};
