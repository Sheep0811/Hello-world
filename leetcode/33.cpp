class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==target)return mid;
            if(nums[l]<=nums[mid])
            {
                if(target>=nums[l] && target<nums[mid])
                {
                    r=mid-1;
                }
                else l=mid+1;
            }
            if(nums[mid]<=nums[r])
            {
                if(target>nums[mid] && target<=nums[r])l=mid+1;
                else r=mid-1;
            }
        }
        return -1;
    }
};


















//O£¨n£©½â·¨
//class Solution {
//public:
    //int search(vector<int>& nums, int target) {
        //int l=0;
        //int r=nums.size()-1;
        //if(l==r && nums[l]==target)return l;
        //while(l<r)
        //{
            //if (target==nums[l])return l;
            
            //if (target==nums[r])return r;

            //if (target<nums[l] && target>nums[r]) return -1;
            //l++;
            //r--;
        //}
        //return -1;
    //}
//};