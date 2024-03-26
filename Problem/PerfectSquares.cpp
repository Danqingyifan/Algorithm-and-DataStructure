// Problem Number: 279
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                // when j*j == i, it means that i is a perfect square number, so dp[i] = 1
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};