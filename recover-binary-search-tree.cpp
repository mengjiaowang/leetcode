class Solution {
    public:
        void recoverTree(TreeNode *root) {
            vector<TreeNode*> vec;
            inorder(root, vec);
            if(vec.size() < 2) return;
            TreeNode *n1 = NULL, *n2 = NULL;

            for(int i = 0; i != vec.size(); ++i){
                if(vec[i]->val > vec[i+1]->val){
                    n1 = vec[i];
                    break;
                }
            }
            for(int i = vec.size() - 1; i >= 0; --i){
                if(vec[i]->val < vec[i-1]->val){
                    n2 = vec[i];
                    break;
                }
            }
            if(n1 != NULL && n2 != NULL){
                int tmp = n1->val;
                n1->val = n2->val;
                n2->val = tmp;
            }
            return;
        }

        void inorder(TreeNode *root, vector<TreeNode*> &vec){
            if(root == NULL) return;
            if(root->left != NULL) inorder(root->left, vec);
            vec.push_back(root);
            if(root->right != NULL) inorder(root->right, vec);
            return;
        }
};
