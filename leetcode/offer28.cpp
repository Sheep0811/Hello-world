/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return is(root->left,root->right);
    }
    bool is(TreeNode* left,TreeNode* right)
    {
        if(left ==nullptr && right==nullptr)return true;
        if(left==nullptr || right==nullptr|| left->val!=right->val)return false;
        return is(left->left,right->right) && is(left->right,right->left);
    }
};