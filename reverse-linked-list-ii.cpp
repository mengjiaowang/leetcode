class Solution {
    public:
        ListNode *reverseBetween(ListNode *head, int m, int n) {
            if(head == NULL) return NULL;
            int count = m - 1;
            ListNode *tail = NULL, *pre = head, *cur = NULL, *next = NULL, *newHead = NULL;
            if(m == 1){
                tail = NULL; pre = NULL; cur = head; next = cur->next; newHead = cur;
            }else{
                while(pre != NULL && count > 1){
                    pre = pre->next; --count;
                }
                tail = pre; cur = pre->next; next = cur->next; pre = NULL; newHead = cur;
            }
            count = n - m + 1;
            while(count != 0 && cur != NULL){
                cur->next = pre; pre = cur; cur = next; -- count; 
                if(next != NULL) next = next->next;
            }
            if(tail != NULL) tail->next = pre;
            else head = pre;
            newHead->next = cur;
            return head;
        }
};
