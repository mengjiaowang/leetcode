class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            if(head == NULL) return NULL;
            if(head->next == NULL) return head;
            ListNode dummyHead(0); dummyHead.next = NULL;
            ListNode *p1 = head, *p2 = head->next, *tail = NULL;

            while(p1 != NULL){
                int distance = 0;
                while(p2 != NULL && p1->val == p2->val){
                    p2 = p2->next; ++ distance;
                }
                if(distance == 0){
                    if(dummyHead.next == NULL){
                        dummyHead.next = p1; tail = p1; tail->next = NULL;
                    }else{
                        tail->next = p1; tail = tail->next; tail->next = NULL;
                    }
                    p1 = p2; if(p2 != NULL) p2 = p2->next;
                }else{
                    p1 = p2; if(p2 != NULL) p2 = p2->next;
                }
            }
            return dummyHead.next;        
        }
};
