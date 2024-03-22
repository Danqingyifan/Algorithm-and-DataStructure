// Problem Number: 55
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int maxReach = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > maxReach)
            {
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};