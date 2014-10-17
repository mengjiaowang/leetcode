class Solution {
    public:
        ListNode *reverseKGroup(ListNode *head, int k) {
            if(head == NULL || k < 2) return head;
            ListNode *p1 = head, *p2 = head, *pre = NULL;
            ListNode *newHead = NULL;

            while(true){
                int step = k - 1;
                while(p2 != NULL && step != 0) {
                    p2 = p2->next; --step;
                }
                if(p2 == NULL){
                    if(pre == NULL) newHead = p1;
                    else pre->next = p1;
                    break;
                }
                ListNode *next = p2->next;
                p2->next = NULL;
                p2 = reverseList(p1);
                if(pre == NULL) newHead = p2;
                else pre->next = p2;
                pre = p1;
                p1 = next;
                p2 = next;
            }
            return newHead;
        }

        ListNode *reverseList(ListNode *head){
            if(head == NULL) return NULL;
            ListNode *pre = NULL, *cur = head, *next;
            while(cur != NULL){
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            return pre;
        }
};
