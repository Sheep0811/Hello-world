class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size()-1;
        while(n>0 && nums[n]<=nums[n-1])n--;
        reverse(nums.begin()+n,nums.end());
        if(n>0)
        {
            int start=n;
            for(;start<nums.size();start++)
            {
                if(nums[start]>nums[n-1])
                {swap(nums[start],nums[n-1]);break;}
            }
        }    
    }
};