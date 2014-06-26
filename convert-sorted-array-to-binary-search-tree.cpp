#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void createBST(TreeNode * root, vector<int> &num, int start, int end);
TreeNode *sortedArrayToBST(vector<int> &num);

TreeNode *sortedArrayToBST(vector<int> &num) {
    if(num.size() == 0) return NULL;
    int start = 0, end = num.size() - 1;
    TreeNode * root = NULL;
    createBST(root, num, start, end);
    return root;
}

void createBST(TreeNode * root, vector<int> &num, int start, int end){
    if(start > end) return;
    int mid = start - (start - end)/2;
    root = new TreeNode(num[mid]);
    createBST(root->left, num, 0, mid-1);
    createBST(root->right, num, mid+1, end);
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6};
    vector<int> num(a, a+6);
    TreeNode * root = sortedArrayToBST(num);
}
