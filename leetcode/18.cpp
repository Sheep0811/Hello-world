class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
vector<vector<int>>ans;
int n=nums.size();
if(n<4)return ans;
sort(nums.begin(),nums.end());
for(int k=0;k<n-3;k++)
{
    if(k>0 && nums[k]==nums[k-1])continue;
    for(int i=k+1;i<n-2;i++)
    {
       if(i>k+1 && nums[i]==nums[i-1])continue;
       //if(nums[k]+nums[i]>target-2*nums[i])return ans;
       int l=i+1;
       int r=n-1;
       while(l<r)
       {
           if( target-nums[l]-nums[r]>nums[k]+nums[i])
            while(l<r && nums[l]==nums[++l]);
           else if(target-nums[l]-nums[r]<nums[k]+nums[i])
               while(l<r && nums[r]==nums[--r]);
           else
           {
               ans.push_back({nums[k],nums[i],nums[l],nums[r]});
               while(l<r && nums[l]==nums[++l]);
               while(l<r && nums[r]==nums[--r]);
           }
       } 
    }
}
return ans;
    }
};