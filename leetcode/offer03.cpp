class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            if(i==nums[i])continue;
            if(nums[i]!=nums[nums[i]])
            {
              swap(nums[i],nums[nums[i]]);  
              i--;
            }
            else 
            return nums[i];
        }
        return -1;
   //     unordered_set<int> num;
   //     int n=nums.size();
   //     for(int i=0;i<n;++i)
   //     {
   //         if(!num.count(nums[i]))num.insert(nums[i]);
   //         else return nums[i];
   //     }
   // return nums[0];
    }
};