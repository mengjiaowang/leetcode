#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
};

ListNode *reverseKGroup(ListNode *head, int k);

int main()
{
    ListNode l1, l2;
    l1.val = 1; l2.val=2;
    l1.next = &l2; l2.next=NULL;
    ListNode *l = reverseKGroup(&l1, 3);
    while(l!=NULL){
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
    return 0;
}

ListNode *reverseKGroup(ListNode *head, int k) {
    if(head == NULL) return NULL;
    ListNode * dummy = head, * p1 = head, * p2 = p1->next;
    int num = 0;
    while(dummy != NULL){
        num ++; dummy = dummy->next;
    }
    if(num < k) return head;

    dummy = NULL;
    while(p1 != NULL && k --){
        p1->next = dummy;
        dummy = p1;
        p1 = p2;
        if(p2 != NULL) p2 = p2->next;
    }
    if(p1 == NULL) head->next = NULL;
    else head->next = p1;
    return dummy;
}
