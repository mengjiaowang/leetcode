class Solution {
    public:

        ListNode *sortList(ListNode *head){
            if(head != NULL && head->next != NULL){
                ListNode * mid = findMid(head);
                ListNode * first = sortList(head);
                ListNode * second = sortList(mid);
                ListNode * merged = mergeLists(first, second); 
                return merged;
            }
            else return head;
        }

        ListNode *findMid(ListNode *head){
            ListNode *p1 = head, *p2 = head;
            while(p2 != NULL && p2->next != NULL){
                p2 = p2->next->next;
                if(p2 != NULL) p1 = p1->next;
            }
            p2 = p1->next;
            p1->next = NULL;
            return p2;
        }

        ListNode *mergeLists(ListNode *head1, ListNode *head2){
            if(head1 == NULL) return head2;
            if(head2 == NULL) return head1;
            ListNode *curHead1 = head1, *curHead2 = head2;
            ListNode *head = NULL, *cur = NULL;
            while(curHead1 != NULL && curHead2 != NULL){
                if(curHead1->val < curHead2->val){
                    if(head == NULL){
                        head = curHead1; cur = head;
                    }
                    else{
                        cur->next = curHead1; cur = cur->next;
                    }
                    curHead1 = curHead1->next;
                }
                else{
                    if(head == NULL){
                        head = curHead2; cur = head;
                    }
                    else{
                        cur->next = curHead2; cur = cur->next;
                    }
                    curHead2 = curHead2->next;
                }
            }

            while(curHead1 != NULL){
                cur->next = curHead1;
                cur = cur->next;
                curHead1 = curHead1->next;
            }

            while(curHead2 != NULL){
                cur->next = curHead2;
                cur = cur->next;
                curHead2 = curHead2->next;
            }
            return head; 
        }

};
