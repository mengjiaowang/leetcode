class Solution {
    public:
        ListNode *sortList(ListNode *head) {
            if(head == NULL) return NULL;
            return sortList(head, NULL);
        }

        ListNode *sortList(ListNode *head, ListNode *end){
            if(head != end && head != NULL){
                ListNode * mid = head;
                ListNode * newHead = getPartitionHead(head, end);
                ListNode * first = sortList(newHead, mid);
                if(mid->next != NULL){
                    ListNode * second = sortList(mid->next, end);
                    mid->next = second;
                }
                return first;
            }
            else return head;
        }

        ListNode *getPartitionHead(ListNode *head, ListNode *end){
            ListNode *first = NULL, *curFirst = first;
            ListNode *second = NULL, *curSecond = first;
            ListNode *cur = head->next;
            while(cur != end && cur != NULL){
                if(cur->val < head->val){
                    if(first == NULL){ first = cur; curFirst = cur;}
                    else{ curFirst->next = cur; curFirst = cur;}
                }else{
                    if(second == NULL){ second = cur; curSecond = cur;}
                    else{ curSecond->next = cur; curSecond = cur;}
                }
                cur = cur->next;
            }
            if(curFirst != NULL){ curFirst->next = head; head->next = second;}
            else { first = head; first->next = second;}
            if(second != NULL) { curSecond->next = end;}
            else head->next = end;
            return first;
        }

};
