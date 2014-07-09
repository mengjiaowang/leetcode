class Solution {
    public:
        ListNode *swapPairs(ListNode *head) {
            if(head != NULL && head->next != NULL){
                ListNode *p1 = head, *p2 = head->next, *p3 = head->next->next;
                p2->next = p1;
                p1->next = swapPairs(p3);
                return p2;
            }
            else{
                return head;
            }
        }
};
