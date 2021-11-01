class Solution
{
public:
    int numWays(int n)
    {
        int a = 1;
        int b = 1;
        int c = 1;
        for (int i = 2; i < n; ++i)
        {
            c = (a + b)%1000000007;
            a = b;
            b = c;
        }
        return c;
    }
};