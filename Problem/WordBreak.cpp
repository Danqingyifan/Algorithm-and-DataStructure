// Problem Number: 139
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        const int maxLength = getMaxLength(wordDict);
        for (int i = 0; i < s.size() + 1; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (i - j > maxLength)
                {
                    break;
                }
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }

private:
    int getMaxLength(const vector<string> &wordDict)
    {
        return max_element(begin(wordDict), end(wordDict),
                           [](const auto &a, const auto &b)
                           {
                               return a.length() < b.length();
                           })
            ->length();
    }
};