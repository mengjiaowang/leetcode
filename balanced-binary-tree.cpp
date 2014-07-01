class Solution {
    public:
        bool isBalanced(TreeNode *root) {
            if(root == NULL) return true;
            if(!isBalanced(root->left) || !isBalanced(root->right)) return false;
            int left = getHeight(root->left);
            int right = getHeight(root->right);
            if(std::abs(left - right) <= 1) return true;
            else return false;
        }

        int getHeight(TreeNode *root){
            if(root == NULL) return 0;
            int left = getHeight(root->left);
            int right = getHeight(root->right);
            int height = left > right ? left : right;
            return height + 1;
        }
};
