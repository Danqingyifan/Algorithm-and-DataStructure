// Problem Number: 20
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() <= 1)
        {
            return s;
        }
        int maxLen = 1;

        std::vector<std::vector<bool>> dp(s.length(), std::vector<bool>(s.length(), false));
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            dp[i][i] = true;
            for (int j = 0; j < i; ++j)
            {
                if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1]))
                {
                    dp[j][i] = true;
                    if (i - j + 1 > maxLen)
                    {
                        maxLen = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};