class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            ListNode *cur1 = l1, *cur2 = l2;
            ListNode * head = NULL, *cur = NULL;
            int flag = 0;
            while(cur1 != NULL && cur2 != NULL){
                int val = cur1->val + cur2->val + flag;
                flag = val / 10; val = val % 10;
                if(head == NULL){
                    head = new ListNode(val); cur = head;
                }else{
                    cur->next = new ListNode(val); cur = cur->next;
                }
                cur1 = cur1->next; cur2 = cur2->next;
            }
            while(cur1 != NULL){
                int val = cur1->val + flag;
                flag = val / 10; val = val % 10;
                if(head == NULL){
                    head = new ListNode(val); cur = head;
                }else{
                    cur->next = new ListNode(val); cur = cur->next;
                }
                cur1 = cur1->next;          
            }
            while(cur2 != NULL){
                int val = cur2->val + flag;
                flag = val / 10; val = val % 10;
                if(head == NULL){
                    head = new ListNode(val); cur = head;
                }else{
                    cur->next = new ListNode(val); cur = cur->next;
                }
                cur2 = cur2->next;          
            }
            if(flag != 0){
                if(head == NULL){
                    head = new ListNode(1); cur = head;
                }else{
                    cur->next = new ListNode(1); cur = cur->next;
                }
            }
            return head;
        }
};
