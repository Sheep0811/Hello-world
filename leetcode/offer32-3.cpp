class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> tmp;
        if (root != NULL)
            tmp.push(root);
        while (tmp.size() != 0)
        {
            int sizee = tmp.size();
            vector<int> path;
            while (sizee--)
            {
                if (tmp.front()->left)
                    tmp.push(tmp.front()->left);
                if (tmp.front()->right)
                    tmp.push(tmp.front()->right);
                path.push_back(tmp.front()->val);
                tmp.pop();
            }
            if(ans.size() & 1)
                reverse(path.begin(), path.end());
                ans.push_back(path);
        }
        return ans;
    }
};