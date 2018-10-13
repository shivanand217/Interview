/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void solve(TreeNode *node, vector<int>& ans) {
    if(node == NULL) {
        return;
    }
    solve(node->left, ans);
    ans.push_back(node->val);
    solve(node->right, ans);
}
 
int Solution::kthsmallest(TreeNode* A, int B) {
    vector<int> ans;
    solve(A, ans);
    return ans[B-1];
}
