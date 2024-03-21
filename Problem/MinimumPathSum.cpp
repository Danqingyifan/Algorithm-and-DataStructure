// Problem Number: 20
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    int DPProcess(vector<vector<int>> &grid)
    {
        const int MAX = 1000000;
        int n = grid.size();
        int m = grid[0].size();
        int **dp = new int *[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            dp[i] = new int[m + 1];
        }
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                dp[i][j] = MAX;
            }
        }
        dp[n - 1][m - 1] = 0;
        dp[n][m - 1] = dp[n - 1][m] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                dp[i][j] = grid[i][j] + std::min(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
    int minPathSum(vector<vector<int>> &grid) { return DPProcess(grid); }
};