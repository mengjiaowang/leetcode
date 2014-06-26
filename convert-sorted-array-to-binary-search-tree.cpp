class Solution {
    public:
        TreeNode *sortedArrayToBST(vector<int> &num) {
            if(num.size() == 0) return NULL;
            int start = 0, end = num.size() - 1;
            TreeNode * root = createBST(num, start, end);
            return root;
        }

        TreeNode * createBST(vector<int> &num, int start, int end){
            if(start > end) return NULL;
            int mid = start - (start - end)/2;
            TreeNode * root = new TreeNode(num[mid]);
            root->left = createBST(num, start, mid-1);
            root->right = createBST(num, mid+1, end);
            return root;
        }
};
