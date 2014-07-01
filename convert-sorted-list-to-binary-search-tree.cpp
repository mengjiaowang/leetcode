class Solution {
    public:
        TreeNode *sortedListToBST(ListNode *head) {
            if(head == NULL) return NULL;
            ListNode *p1 = head, *p2 = head, *pre = NULL;
            while(p2->next != NULL && p2->next->next != NULL){
                pre = p1; p1 = p1->next;
                p2 = p2->next->next;
            }
            TreeNode *root = new TreeNode(p1->val);
            if(pre != NULL){
                pre->next = NULL;
                root->left = sortedListToBST(head);
            }
            root->right = sortedListToBST(p1->next);
            return root;
        }
};
