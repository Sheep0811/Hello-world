class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int tmp = 0;
        //int n = nums.size();
        for (int i = 0; i < 4;++i)  
        {
            if(nums[i]==0)
                tmp++;
            else if(nums[i]==nums[i+1])
                return false;
        }
        return nums[4] - nums[tmp] < 5;
        //for (int i = 0; i < n-1; ++i)
        //{
        //    if(nums[i]==0)
        //        tmp++;
        //    else
        //    {
        //        if(nums[i+1]-nums[i]-1>tmp)
        //            return false;
        //        tmp -= nums[i + 1] - nums[i] - 1;
        //    }
        //}
        //return true;
    }
};