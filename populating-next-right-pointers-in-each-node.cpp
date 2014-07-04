class Solution {
    public:
        void connect(TreeLinkNode *root) {
            if(root == NULL) return;
            queue<TreeLinkNode *> q; q.push(root);
            int level = 1;
            while(!q.empty()){
                for(int i = 0; i != level; ++i){
                    TreeLinkNode *tmp = q.front(); q.pop();
                    if(i != level - 1) tmp->next = q.front();
                    else tmp->next = NULL;
                    if(tmp->left != NULL) q.push(tmp->left);
                    if(tmp->right != NULL) q.push(tmp->right);
                }
                level = level << 1;
            }
        }
};
