nclude <queue>
class Solution {
    public:
        int maxDepth(TreeNode *root) {
            if(root == NULL)return 0;
            int depth = 0;
            TreeNode * endOfLayer = root;
            std::queue<TreeNode *> q;
            q.push(root);
            while(!q.empty()){
                TreeNode * tmp = q.front();
                q.pop();
                if(tmp->left  != NULL) q.push(tmp->left);
                if(tmp->right != NULL) q.push(tmp->right);
                if(tmp == endOfLayer){
                    depth ++;
                    endOfLayer = q.back();
                }
            }
            return depth;
        }
};
