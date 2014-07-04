class Solution {
    public:
        void connect(TreeLinkNode *root) {
            if(root == NULL) return;
            queue<TreeLinkNode*> q; q.push(root);
            int count1 = 1, count2 = 0;
            while(!q.empty()){
                while(count1 --){
                    TreeLinkNode *tmp = q.front(); q.pop();
                    if(count1 == 0) tmp->next = NULL;
                    else tmp->next = q.front();
                    if(tmp->left != NULL){
                        q.push(tmp->left); count2++;
                    }
                    if(tmp->right != NULL){
                        q.push(tmp->right); count2++;
                    }
                }
                count1 = count2; count2 = 0;
            }
        }
};
