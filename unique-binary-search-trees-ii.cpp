class Solution {
    public:
        vector<TreeNode *> generateTrees(int n) {
            vector<TreeNode*> result;
            generateTrees(result, 1, n);
            return result;
        }

        void generateTrees(vector<TreeNode*> &tree, int start, int end) {
            if(start > end){
                tree.push_back(NULL);
            }
            for(int i = start; i <= end; ++i) {
                vector<TreeNode*> left, right;
                generateTrees(left, start, i - 1);
                generateTrees(right, i + 1, end);
                for(int j = 0; j != left.size(); ++j){
                    for(int k = 0; k != right.size(); ++k){
                        TreeNode *root = new TreeNode(i);
                        root->left = left[j];
                        root->right = right[k];
                        tree.push_back(root);
                    }
                }
            }
        }
};
