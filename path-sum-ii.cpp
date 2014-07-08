class Solution {
    public:
        vector<vector<int> > pathSum(TreeNode *root, int sum) {
            vector<vector<int> > result;
            vector<int> path;
            pathSum(root, sum, path, result);
            return result;
        }
        
        void pathSum(TreeNode *root, int sum, vector<int> &path, vector<vector<int> > &result){
            if(root == NULL) return;
            if(root->left != NULL && root->right == NULL){
                path.push_back(root->val);
                pathSum(root->left, sum-root->val, path, result);
                path.pop_back();
            }else if(root->left == NULL && root->right != NULL){
                path.push_back(root->val); 
                pathSum(root->right, sum-root->val, path, result);
                path.pop_back();
            }else if(root->left != NULL && root->right != NULL){
                path.push_back(root->val); 
                pathSum(root->left, sum-root->val, path, result);
                path.pop_back();
                path.push_back(root->val); 
                pathSum(root->right, sum-root->val, path, result);
                path.pop_back();
            }else{
                if(sum == root->val){
                    path.push_back(root->val); 
                    result.push_back(path);
                    path.pop_back();
                }
            }

        }
};
