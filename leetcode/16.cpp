class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
int ans=INT_MAX/2;
sort(nums.begin(),nums.end());
int n=nums.size();
for(int i=0;i<n-2;i++)
{
    if(i>0 && nums[i]==nums[i-1])continue; 
    int l=i+1, r=n-1;
    while(l<r)
    {    
        int s=nums[i]+nums[l]+nums[r];
        if(s==target)return target;
        if(abs(s-target)<abs(ans-target))ans=s;
        if(s<target)
        while(l<r && nums[l]==nums[++l]);
        else if(s>target)
        while(l<r && nums[r]==nums[--r]);
    }
}
return ans;
    }
};
 