class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @param k int整型 
     * @return long长整型
     */
    long long ans(vector<int>& array, int k) {
        // write code here
        sort(array.begin(),arry.end());
        long long ans=0;
        int n=array.size();
        int l=0,r=array.size()-1;
        for(int i=0;i<n-1;++i)
        {
            if(array[i]>k)break;
            while(l<r && array[l]+array[r]>k)
            {
                r--;
            }
            ans+=l-r;
        }
        return ans;
    }
};
