class Solution {
public:
    int search(vector<int>& nums, int target) {
           if(nums.empty())return 0;
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int mid=l+r>>1;
            if(target>nums[mid])l=mid+1;
            else r=mid;
        }
        int tmp=r;
        l=r;
        r=nums.size()-1;
        while(l<r)
        {
            int mid=l+r+1>>1;
            if(target<nums[mid])r=mid-1;
            else l=mid;
        } 
        return nums[tmp]==target?r-tmp+1:0;
      //  for(int i=r;i<n;++i)
      //  {
      //      if(nums[i]==target)
      //      {++count;}
      //      else break;
      //  }
      //  return count;
    } 
};