class Solution {
    public:
        bool isValidBST(TreeNode *root) {
            if(root == NULL) return true;
            vector<int> seq;
            inOrderTraversal(root, seq);
            for(int i = 1; i != seq.size(); ++i){
                if(seq[i] <= seq[i-1]) return false;
            }
            return true;
        }

        void inOrderTraversal(TreeNode * root, vector<int> & seq){
            if(root == NULL) return;
            if(root->left != NULL) inOrderTraversal(root->left, seq);
            seq.push_back(root->val);
            if(root->right != NULL) inOrderTraversal(root->right, seq);
        }
};
