class Solution {
    public:
        int sumNumbers(TreeNode *root) {
            if(root == NULL) return 0;
            queue<TreeNode *> q1; queue<int> q2;
            int result = 0;
            q1.push(root); q2.push(root->val);
            while(!q1.empty()){
                TreeNode *tmp = q1.front(); q1.pop();
                int value = q2.front(); q2.pop();
                if(tmp->left == NULL && tmp->right == NULL){
                    result += value;
                }
                else if(tmp->left != NULL && tmp->right == NULL){
                    q1.push(tmp->left);
                    q2.push(tmp->left->val + value * 10);
                }
                else if(tmp->right != NULL && tmp->left == NULL){
                    q1.push(tmp->right);
                    q2.push(tmp->right->val + value * 10);
                }
                else{
                    q1.push(tmp->left);
                    q1.push(tmp->right);
                    q2.push(tmp->left->val + value * 10);
                    q2.push(tmp->right->val + value * 10);
                }
            }
            return result;
        }
};
