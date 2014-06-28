class Solution {
    public:
        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
            return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1); 
        }

        TreeNode * buildTree(vector<int> &inorder, int startInOrder, int endInOrder,
                vector<int> &postorder, int startPostOrder, int endPostOrder)
        {
            if(inorder.size() == 0 || startInOrder > endInOrder || startPostOrder > endPostOrder) return NULL;
            TreeNode * root = new TreeNode(postorder[endPostOrder]);
            int rootIndex = startInOrder;
            for(; rootIndex <= endInOrder; ++ rootIndex){
                if(inorder[rootIndex] == postorder[endPostOrder]) break;
            }
            root->left = buildTree(inorder, startInOrder, rootIndex - 1, 
                    postorder, startPostOrder, startPostOrder + (rootIndex - startInOrder) - 1);
            root->right = buildTree(inorder, rootIndex + 1, endInOrder,
                    postorder, startPostOrder + (rootIndex - startInOrder), endPostOrder - 1);
        }
};
