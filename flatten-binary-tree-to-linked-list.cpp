class Solution {
    public:
        void flatten(TreeNode *root) {
            if(root == NULL) return;
            flatten(root->left); flatten(root->right);
            if(root->left != NULL && root->right != NULL){
                TreeNode * tmp = root->right, * cur = root->left;
                root->right = root->left;
                root->left = NULL;
                while(cur->right != NULL) cur = cur->right;
                cur->right = tmp;
            }
            else if(root->left != NULL && root->right == NULL){
                root->right = root->left;
                root->left = NULL;
            }
        }
};
