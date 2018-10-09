/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/
 
void inorder(TreeNode *A, vector<int> &a){
    if(A == NULL){
        return;
    }
    inorder(A->left, a);
    a.push_back(A->val);
    inorder(A->right, a);
}
 
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    
    if(A == NULL && B == NULL){
        return 1;
    }
    vector<int> a,b;
    inorder(A, a);
    inorder(B, b);
    
    if(a.size() != b.size()) { 
        return 0;
    }
    if(a.size() == 0){
        return 1;
    }
    for(int i=0;i<a.size();i++){
        if(a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}
