class Solution {
    public:
        bool hasPathSum(TreeNode *root, int sum) {
            if(root == NULL) return false;

            if(root->right != NULL && root->left == NULL)
                return hasPathSum(root->right, sum - root->val);
            else if(root->left != NULL && root->right == NULL) 
                return hasPathSum(root->left, sum - root->val);
            else if(root->left != NULL && root->right != NULL)
                return hasPathSum(root->right, sum - root->val) | hasPathSum(root->left , sum - root->val);

            if(sum - root->val == 0) return true;
            else return false;
        }
};
