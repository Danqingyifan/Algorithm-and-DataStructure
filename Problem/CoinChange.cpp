// Problem Number: 322
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                // 如果 i - coins[j] == 0，那么说明当前的硬币就是一个base case，所以dp[i] = 1
                if (i - coins[j] >= 0)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};