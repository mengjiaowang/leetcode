class Solution {
    public:
        ListNode *mergeKLists(vector<ListNode *> &lists) {
            ListNode * head = NULL;
            ListNode * cur = NULL;
            vector<ListNode*> headers(lists);
            head = findMinAndUpdate(headers);
            cur = head;
            while(cur != NULL){
                cur->next = findMinAndUpdate(headers);
                cur = cur->next;
            }
            return head;
        }

        ListNode *findMinAndUpdate(vector<ListNode *> &headers) {
            int minValue = std::numeric_limits<int>::max();
            ListNode * minPointer = NULL;
            int minIndex = -1;
            for(int i = 0; i != headers.size(); ++i){
                if(headers[i] == NULL) continue;
                if(headers[i]->val < minValue){
                    minValue = headers[i]->val;
                    minPointer = headers[i];
                    minIndex = i;
                }
            }
            if(minIndex != -1) headers[minIndex] = headers[minIndex]->next;
            return minPointer;
        }
};
