class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int mid=l+r>>1;
            if(nums[mid]==mid) l=mid+1;
            else r=mid-1;
        }
        return r;
     //   int n=nums.size();
     //   for(int i=0;i<n;++i)
     //   {
     //       if(nums[i]>i)return i-1;
     //   }
     //   return -1;
    }
};