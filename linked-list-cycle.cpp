class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode * p1 = head, * p2 = head;
            while(p1 != NULL && p2 != NULL){
                p2 = p2->next;
                if(p2 == p1) return true;
                if(p2 == NULL) return false;
                p1 = p1->next;
                p2 = p2->next;
                if(p2 == p1) return true;
            }
            return false;
        }
};
