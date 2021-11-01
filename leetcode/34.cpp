class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //vector<int> ans;
        int l=0;
        int r=nums.size()-1;
        if(nums.size()==0)return{-1,-1};
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(nums[mid]>=target)r=mid;
            else l=mid+1;
        }
        if(nums[r]!=target)return {-1,-1};
        l=r;
        int L=r;
        r=nums.size()-1;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(nums[mid]<=target)l=mid;
            else r=mid-1;
        }
        return {L,r};
    }
};