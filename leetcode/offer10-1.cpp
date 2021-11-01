class Solution
{
public:
    //int a[101];
    int fib(int n)
    {
        if (n < 2)
            return n;
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; ++i)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
        // a[0] = 0;
        // a[1] = 1;
        // for (int i = 2; i <= n;++i)
        // {
        //     a[i] = (a[i - 1] + a[i - 2])%1000000007;
        // }
        // return a[n];
    }
};