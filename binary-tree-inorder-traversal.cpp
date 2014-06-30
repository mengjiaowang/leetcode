class Solution {
    public:
        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> result;
            stack<TreeNode *> s;
            TreeNode * cur = root;
            while(cur != NULL || !s.empty()){
                while(cur != NULL){
                    s.push(cur);
                    cur = cur->left;
                }
                if(!s.empty()){
                    cur = s.top();
                    s.pop();
                    result.push_back(cur->val);
                    cur = cur->right;
                }
            }
            return result;
        }
};
