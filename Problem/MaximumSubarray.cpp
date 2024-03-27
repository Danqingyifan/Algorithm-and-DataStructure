// Problem Number: 53
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};

// Kadane's Algorithm 的基本思想是在每个数组索引处，计算以该索引结尾的最大子数组和。然后，从这些结果中找出最大的值，即为整个数组的最大子数组和