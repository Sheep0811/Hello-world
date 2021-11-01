class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        for (int i = 0; i < n;++i)
        {
            ans.push_back(to_string(nums[i]));
        }
        sort(ans.begin(), ans.end(), [](string a, string b)
             { return a + b < b + a; });
        for (int i = 1; i < n;++i)
        {
            ans[0] += ans[i];
        }
        return ans[0];
    }
    struct cmp{
        bool operator()(string a,string b)
    {
        return a + b < b + a;
    }
    }
    
};