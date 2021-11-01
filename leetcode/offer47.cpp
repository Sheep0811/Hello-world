class Solution
{
public:
    int dp[201][201] = {0};
    int maxValue(vector<vector<int>> &grid)
    {
        int x = grid.size();
        int y = grid[0].size();
        for (int i = 0; i < x; ++i)
        {
            for (int k = 0; k < y; ++k)
            {
                if (i == 0 && k == 0)
                {
                    dp[i][k] = grid[i][k];
                    continue;
                }
                else if (i == 0)
                {
                    dp[i][k] = dp[i][k - 1] + grid[i][k];
                    continue;
                }
                else if (k == 0)
                {
                    dp[i][k] = dp[i - 1][k] + grid[i][k];
                    continue;
                }
                dp[i][k] = max(dp[i - 1][k], dp[i][k - 1]) + grid[i][k];
            }
        }
        return dp[x - 1][y - 1] + grid[0][0];
    }
};