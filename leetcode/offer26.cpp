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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B==nullptr)
            return false;
        return dfs(A->left, B) || dfs(A->right, B);
    }
    bool dfs(TreeNode* a,TreeNode* b)
    {
        if(b==nullptr)
            return true;
        if(a==nullptr || a->val!=b->val)
            return false;
        return dfs(A->left, B->left) && dfs(A->right, B->right);
    }
};