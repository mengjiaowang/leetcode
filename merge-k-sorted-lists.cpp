class Solution {
    public:
        ListNode *mergeKLists(vector<ListNode *> &lists) {
            ListNode * head = NULL, *cur = NULL;
            if(lists.size() == 0) return head;
            multimap<int, ListNode*> heap;
            for(int i = 0; i != lists.size(); ++i){
                if(lists[i] != NULL)
                    heap.insert(pair<int, ListNode*>(lists[i]->val,lists[i]));
            }
            multimap<int, ListNode*>::iterator min;
            while(!heap.empty()){
                min = heap.begin();
                if(head == NULL){
                    head = min->second;
                    cur = min->second;
                }else{
                    cur->next = min->second;
                    cur = cur->next;
                }
                if(min->second->next != NULL){
                    heap.insert(pair<int, ListNode*>(min->second->next->val,min->second->next));
                }
                heap.erase(min);
            }
            return head;
        }
};
