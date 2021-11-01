class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
       dfs(0,nums.size(),nums); 
       return ans;
    }
    void dfs(int begin,int end,vector<int>& nums)
    {
        if(begin==end)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=begin;i<end;i++)
        {
            swap(nums[i],nums[begin]);
            dfs(begin+1,end,nums);
            swap(nums[i],nums[begin]);
        }
    }
};