class Solution {
    public:
        bool isSymmetric(TreeNode *root) {
            if(root == NULL) return true;
            return isSymmetric(root->left, root->right);
        }

        bool isSymmetric(TreeNode *node1, TreeNode *node2){
            if(node1 == NULL && node2 == NULL) return true;
            if(node1 == NULL || node2 == NULL) return false;
            return (node1->val == node2->val) && isSymmetric(node1->left, node2->right) && isSymmetric(node1->right, node2->left);
        }
};
