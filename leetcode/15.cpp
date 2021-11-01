class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
vector<vector<int>>ans;
int n=nums.size();
if(n<3)return ans;
sort(nums.begin(),nums.end());

for(int i=0;i<n-2;i++)
{
    if(nums[i]>0)break;
    if(i>0 && nums[i]==nums[i-1])continue;
    int l=i+1;
    int r=n-1;
    while(l<r)
    {
        int count=nums[i]+nums[l]+nums[r];
        if(count>0)r--;
        else if(count<0)l++;
        else
        {
            ans.push_back({nums[i],nums[l],nums[r]});
            while(l<r && nums[l]==nums[++l]);
            while(l<r && nums[r]==nums[--r]);
        }
    }
}
return ans;
    }
};