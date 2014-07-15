class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            if(head == NULL) return NULL;
            RandomListNode *headNew = NULL, *curNew = headNew, *curOriginal = head, *rand = head->random;
            while(curOriginal != NULL){
                if(headNew == NULL){
                    headNew = new RandomListNode(curOriginal->label);
                    curNew = headNew;
                }
                else{
                    curNew->next = new RandomListNode(curOriginal->label);
                    curNew = curNew->next;
                }
                curOriginal = curOriginal->next;
            }
            curOriginal = head; curNew = headNew;
            while(curOriginal != NULL && curNew != NULL){
                RandomListNode *cur1 = head, *cur2 = headNew;
                if(curOriginal->random == NULL) curNew->random = NULL;
                else{
                    while(cur1 != curOriginal->random){
                        cur1 = cur1->next;
                        cur2 = cur2->next;
                    }
                    curNew->random = cur2;
                }
                curOriginal = curOriginal->next;
                curNew = curNew->next;
            }
            return headNew;
        }
};
