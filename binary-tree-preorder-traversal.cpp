/**
 ** Definition for binary tree
 ** struct TreeNode {
 **     int val;
 **     TreeNode *left;
 **     TreeNode *right;
 **     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ** };
 **/

#include<vector>
#include<stack>

class Solution {
    public:
        vector<int> preorderTraversal(TreeNode *root) {

            vector<int> result;
            if(root != NULL)
            {
                stack<TreeNode *> s;
                s.push(root);
                while(!s.empty())
                {
                    TreeNode *cur = s.top();
                    s.pop();
                    result.push_back(cur->val);
                    if(cur->right != NULL) s.push(cur->right);
                    if(cur->left  != NULL) s.push(cur->left);
                }
            }
            return result;
        }
};
