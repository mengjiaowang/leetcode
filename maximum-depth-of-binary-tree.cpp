class Solution {
    public:
        int maxDepth(TreeNode *root) {
            if(root == NULL)return 0;
            else{
                int left = maxDepth(root->left);
                int right = maxDepth(root->right);
                int sub_dep = left > right ? left : right;
                return sub_dep + 1;
            }
        }
};
