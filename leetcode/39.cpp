class Solution {
public:
        vector<vector<int>> ans;
        vector<int>path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,0,target);
        return ans;
    }
    void dfs(vector<int>&c,int u,int target)
    {
        if(target<0)return;
        if(target==0){
            ans.push_back(path);
            return;
        }
        for(int i=u;i<c.size();i++)
        {
            if(c[i]<=target)
            {
                path.push_back(c[i]);
                dfs(c,i,target-c[i]);
                path.pop_back();
            }
        }
    }
};