class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            if(head == NULL) return NULL;
            RandomListNode *headNew = NULL, *curNew = headNew, *curOriginal = head;
            unordered_map<RandomListNode*, RandomListNode*> mapping;
            while(curOriginal != NULL){
                if(headNew == NULL){
                    headNew = new RandomListNode(curOriginal->label);
                    curNew = headNew;
                }
                else{
                    curNew->next = new RandomListNode(curOriginal->label);
                    curNew = curNew->next;
                }
                mapping[curOriginal] = curNew;
                curOriginal = curOriginal->next;
            }
            curOriginal = head; curNew = headNew;
            mapping[NULL] = NULL;
            while(curOriginal != NULL && curNew != NULL){
                curNew->random = mapping[curOriginal->random];
                curOriginal = curOriginal->next;
                curNew = curNew->next;
            }
            return headNew;
        }

};
