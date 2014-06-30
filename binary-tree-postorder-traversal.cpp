class Solution {
    public:
        vector<int> postorderTraversal(TreeNode *root) {
            vector<int> result;
            if(root == NULL) return result;
            stack<TreeNode *> s;
            TreeNode *cur = root, *pre = NULL;
            s.push(cur);
            while(!s.empty()){
                cur = s.top();
                if((cur->left == NULL && cur->right == NULL) || 
                   (pre != NULL && (pre == cur->right || pre == cur->left))){
                    result.push_back(cur->val);
                    s.pop();
                    pre = cur;
                }
                else{
                    if(cur->right != NULL) s.push(cur->right);
                    if(cur->left != NULL) s.push(cur->left);
                }    
            }
            return result;
        }
};
