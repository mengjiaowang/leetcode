class Solution {
    public:
        int maxPathSum(TreeNode *root) {
            if(root == NULL) return 0;
            int max = root->val;
            maxPathSumHelper(root, max);
            return max;
        }

        int maxPathSumHelper(TreeNode *root, int &max){
            if(root == NULL) return 0;
            int res = root->val;
            int left = maxPathSumHelper(root->left, max);
            int right = maxPathSumHelper(root->right, max);

            if(res < left + root->val) res = left + root->val;
            if(res < right + root->val) res = right + root->val;

            if(root->left != NULL && max < left) max = left;
            if(root->right != NULL && max < right) max = right;
            if(max < left + root->val) max = left + root->val;
            if(max < right + root->val) max = right + root->val;
            if(max < left + right + root->val) max = left + right + root->val;

            return res;
        }
};
