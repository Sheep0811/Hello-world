class Solution {
public:
        vector<vector<int>> ans;
        vector<int>path;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
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
            if(i-1>=u && c[i-1]==c[i]&&)continue;
                path.push_back(c[i]);
                dfs(c,i+1,target-c[i]);
                path.pop_back();
        }
    }
};