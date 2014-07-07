class Solution {
    public:
        vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
            vector<vector<int> > result;
            if(root == NULL) return result;
            queue<TreeNode*> q; q.push(root);
            vector<int> levelSet;
            int count1 = 1, count2 = 0, level = 1;
            while(!q.empty()){
                TreeNode *tmp = q.front(); q.pop();
                levelSet.push_back(tmp->val);
                count1 --;
                if(tmp->left != NULL){
                    q.push(tmp->left); count2 ++;
                }
                if(tmp->right != NULL){
                    q.push(tmp->right); count2 ++;
                }                 
                if(count1 == 0){
                    count1 = count2; count2 = 0;
                    if(level % 2 == 0) reverse(levelSet.begin(), levelSet.end());
                    ++ level;
                    result.push_back(levelSet);
                    levelSet.clear();
                }
            }

            return result;
        }
};
