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
    int kthLargest(TreeNode* root, int k) {
        stack<int> q;
        dfs(root, q);
        while(k-->1)
            q.pop();
        return q.top();
    }
    void dfs(TreeNode* root,stack<int>& q)
    {
        if(root==nullptr)
            return;
        dfs(root->left, q);
        q.push(root->val);
        dfs(root->right, q);
    }
};