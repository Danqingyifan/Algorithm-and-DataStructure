// Problem Number: 20
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int DPProcess(string word1, string word2)
    {
        // init
        const int MAX = 1000000;
        int n = word1.length();
        int m = word2.length();
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
        // base case
        dp[n][m] = 0;
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][m] = n - i;
        }
        for (int j = 0; j < m + 1; j++)
        {
            dp[n][j] = m - j;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (word1[i] == word2[j])
                    dp[i][j] = dp[i+1][j+1];
                else
                    dp[i][j] = 1 + min(min(dp[i+1][j],dp[i][j+1]),dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2)
    {
        return DPProcess(word1, word2);
    }
};
