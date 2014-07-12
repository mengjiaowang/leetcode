class Solution {
    public:
        void reorderList(ListNode *head) {
            if(head == NULL) return;
            ListNode *l1 = head, *l2 = reverseList(breakList(head));
            head = mergeList(l1, l2);
        }

        ListNode * mergeList(ListNode * n1, ListNode * n2){
            ListNode *head = n1, *cur = head;
            n1 = n1->next;
            for(int i = 1; n1 != 0 || n2 != 0; ++i){
                if(i % 2 == 1){
                    cur->next = n2; n2 = n2->next; cur = cur->next;
                }else{
                    cur->next = n1; n1 = n1->next; cur = cur->next;
                }
            }
            return head;
        }

        ListNode * reverseList(ListNode * node){
            if(node != NULL && node->next != NULL){
                ListNode *p1 = NULL, *p2 = node, *p3 = node->next;
                while(p2 != NULL){
                    p2->next = p1; p1 = p2; p2 = p3; 
                    if(p3 != NULL) p3 = p3->next;
                }
                return p1;
            }else return node;
        }

        ListNode * breakList(ListNode * node){
            if(node != NULL && node->next != NULL){
                ListNode *p1 = node, *p2 = node;
                while(p2 != NULL && p2->next != NULL){
                    p2 = p2->next->next;
                    if(p2 != NULL)p1 = p1->next;
                }
                p2 = p1; p1 = p1->next; p2->next = NULL;
                return p1;
            }
            return NULL;
        }
};
