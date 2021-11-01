class Solution {
public:
    int movingCount(int m, int n, int k) {
        int ans = 0;
        int x = 0, y = 0;
        while(size(x)<=k&& x<m)
            ++x;
        while(size(y)<=k && y<n)
            ++y;
        int cou = 10;
        if(k>=9)
            cou = (k - 7) * 10;
        for (int i = 0; i < x;++i)
        {
            for (int j = 0; j < y && i+j<cou;++j)
            {
                if (size(i)+size(j)<=k)
                {
                    ++ans;
                }
            }
        }
        return ans;
    }
    int size(int a)
    {
        int ans = 0;
        while(a!=0)
        {
            ans += a % 10;
            a /= 10;
        }
        return ans;
    }
};