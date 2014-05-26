/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode(int x) : val(x), next(NULL) {}
 ** };
 **/
class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            ListNode *p1 = head, *p2 = head;
            int step = n + 1;
            while(p1 != NULL && step > 0)
            {
                p1 = p1->next;
                step --;
            }
            if(step != 0) 
            {
                return head->next;
            }
            while(p1 != NULL)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            p2->next = p2->next->next;
            return head;
        }
};
