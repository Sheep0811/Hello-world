class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int n=nums.size();
        int q=0;
        for(int i=0;i<n;++i)
        {
            q^=nums[i];
        }
        q=q==INT_MIN?q:q&(-q);//100100 011100
        int x=0,y=0;
        for(int i=0;i<n;++i)
        {
            if(nums[i]&q)
            x^=nums[i];
            else
            y^=nums[i];
        }
        return vector<int>{x,y};
    }
};