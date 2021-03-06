class Solution {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> result;
            stack<TreeNode *> s;
            TreeNode * cur = root;
            while(cur != NULL || !s.empty()){
                while(cur != NULL){
                    result.push_back(cur->val);
                    s.push(cur);
                    cur = cur->left;
                }
                if(!s.empty()){
                    cur = s.top();
                    s.pop();
                    cur = cur->right;
                }
            }
            return result;
        }
};
