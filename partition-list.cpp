class Solution {
    public:
        ListNode *partition(ListNode *head, int x) {
            ListNode *firstHead = NULL, *secondHead = NULL;
            ListNode *firstTail = NULL, *secondTail = NULL;
            ListNode *tmp = NULL;
            while(head != NULL){
                tmp = head->next;
                head->next = NULL;
                if(head->val < x){
                    if(firstHead == NULL) {
                        firstHead = head;
                        firstTail = head;
                    }
                    else {
                        firstTail->next = head;
                        firstTail = firstTail->next;
                    }

                }else {
                    if(secondHead == NULL) {
                        secondHead = head;
                        secondTail = head;
                    }
                    else {
                        secondTail->next = head;
                        secondTail = secondTail->next;
                    }
                }
                head = tmp;
            }
            if(firstHead != NULL) {
                firstTail->next = secondHead;
                return firstHead;
            }
            else {
                return secondHead;
            }
        }
};
