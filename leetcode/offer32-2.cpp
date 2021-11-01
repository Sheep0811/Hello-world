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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(ans, root, 0);
        return ans;
    }
private:
    void dfs(vector<vector<int>> ans,TreeNode* root,int level)
    {
        if(root==nullptr)
            return;
        if(level>=ans.size())
            ans.push_back(vector<int>());
        ans[level].push_back(root->val);
        dfs(ans, root->left, level + 1);
        dfs(ans, root->right, level + 1);
    }
};