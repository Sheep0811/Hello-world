class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> count;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
           ++count[nums[i]]; 
        }
        for(auto i:count)
        {
            if(i.second==1)
            return i.first;
        }
        return -1;
    }
};