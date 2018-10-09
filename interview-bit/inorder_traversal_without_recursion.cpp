/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<iostream>

vector<int> Solution::inorderTraversal(TreeNode* A) {

    vector<int> ans;
    stack<int> my_stack;
    TreeNode *root = A;
    TreeNode *current = A->left;
    TreeNode *top;

    my_stack.push(root);
    while(!my_stack.empty()) {
        
        if(current == NULL) {
            top = my_stack.top();
            my_stack.pop();
            ans.push_back(top->val);
            current = current->right;

        } else {
            my_stack.push(current);
            current = current->left;
        }
    }

    return ans;
}