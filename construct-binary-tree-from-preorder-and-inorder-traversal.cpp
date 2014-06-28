class Solution {
    public:
        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
            return buildTree(preorder, 0, preorder.size() - 1,
                    inorder, 0, inorder.size() - 1);
        }

        TreeNode *buildTree(vector<int> &preorder, int startPreOrder, int endPreOrder,
                vector<int> &inorder, int startInOrder, int endInOrder)
        {
            if(preorder.size() == 0 || startPreOrder > endPreOrder || startInOrder > endInOrder) return NULL;
            TreeNode * root = new TreeNode(preorder[startPreOrder]);
            int rootIndex = startInOrder;
            for(; rootIndex <= endInOrder; ++rootIndex){
                if(preorder[startPreOrder] == inorder[rootIndex]) break;
            }
            root->left = buildTree(preorder, startPreOrder + 1, startPreOrder + (rootIndex - startInOrder),
                    inorder, startInOrder, rootIndex - 1);
            root->right = buildTree(preorder, startPreOrder + (rootIndex - startInOrder) + 1, endPreOrder,
                    inorder, rootIndex + 1, endInOrder);
        }
};
