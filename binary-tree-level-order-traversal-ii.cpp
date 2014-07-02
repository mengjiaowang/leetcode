class Solution {
    public:
        vector<vector<int> > levelOrderBottom(TreeNode *root) {
            vector<vector<int> > result;
            if(root == NULL) return result;
            queue<TreeNode*> q; int count1 = 1, count2 = 0;
            q.push(root);
            vector<int> tmp;
            result.push_back(tmp);
            while(!q.empty()){
                result.back().push_back(q.front()->val);
                count1 --;
                if(q.front()->left != NULL){
                    q.push(q.front()->left); count2 ++;
                }
                if(q.front()->right != NULL){
                    q.push(q.front()->right); count2 ++;
                }
                q.pop();
                if(count1 == 0 && !q.empty()){
                    vector<int> tmp;
                    result.push_back(tmp);
                    count1 = count2;
                    count2 = 0;
                }
            }
            std::reverse(result.begin(), result.end());
            return result;
        }
};

