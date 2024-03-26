// Problem Number: 20
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        int **dp = new int *[numRows];
        for (int i = 0; i < numRows; i++)
        {
            dp[i] = new int[i + 1];
            dp[i][0] = 1;
            dp[i][i] = 1;
        }
        for (int i = 2; i < numRows; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        for (int i = 0; i < numRows; i++)
        {
            vector<int> temp;
            temp.assign(dp[i], dp[i] + i + 1);
            result.push_back(temp);
        }
        return result;
    }
};