#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int dp[103][103];

        int h = int(obstacleGrid.size());
        int w = int(obstacleGrid[0].size());

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                dp[i][j] = 0;
        if (obstacleGrid[0][0] != 1)
            dp[0][0] = 1;

        for (int i = 1; i < h; i++)
        {
            if (obstacleGrid[i][0] != 1)
                dp[i][0] += dp[i - 1][0];
            else
                dp[i][0] = 0;
        }

        for (int j = 1; j < w; j++)
        {
            if (obstacleGrid[0][j] != 1)
                dp[0][j] += dp[0][j - 1];
            else
                dp[0][j] = 0;
        }

        for (int i = 1; i < h; i++)
        {
            for (int j = 1; j < w; j++)
            {
                if (obstacleGrid[i][j] != 1)
                    dp[i][j] += dp[i][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = 0;
            }
        }

        return dp[h - 1][w - 1];
    }
};