class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode * p1 = head, *p2 = head;

            while(p1 != NULL && p1->next != NULL){
                p1 = p1->next->next;
                p2 = p2->next;
                if(p1 == p2) break;
            }

            if(p1 == NULL || p1->next == NULL)
                return NULL;

            p1 = head;

            while(p1 != p2){
                p1 = p1->next;
                p2 = p2->next;
            }
            return p1;
        }
};
