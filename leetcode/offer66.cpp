class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n=a.size();
        vector<int>ans(n,1);
        int left=1;
        for(int i=0;i<n;++i)
        {
            ans[i]*=left;
            left=a[i];
        }
        left=1;
        for(int i=n-1;i>=0;--i)
        {
            ans[i]*=left;
            left*=a[i];
        }
        return ans;
    }
};