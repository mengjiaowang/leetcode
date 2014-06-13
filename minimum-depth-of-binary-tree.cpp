class Solution {
    public:
        int minDepth(TreeNode *root) {
            if(root == NULL) return 0;
            queue<TreeNode*> q;
            int depth = 1; int level = 1;
            q.push(root);
            while(!q.empty()){
                int count = level;
                level = 0;
                while(count --){
                    TreeNode * cur = q.front();
                    q.pop();
                    if(cur->left == NULL && cur->right == NULL) return depth;
                    if(cur->left != NULL ){q.push(cur->left ); level ++;}
                    if(cur->right != NULL){q.push(cur->right); level ++;}
                }
                depth ++;
            }
        }
};
