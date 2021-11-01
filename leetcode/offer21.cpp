class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l<r)
        {
            if(nums[l]&1==0 && nums[r]&1==1)
            {
                swap(nums[l], nums[r]);
                ++l;
                --r;
            }
            else if(nums[l]&1==0)
            {
                --r;
            }
            else if(nums[r]&1==1)
            {
                ++l;
            }
            else 
            {
                ++l;
                --r;
            }
        }
        return nums;
    }
};