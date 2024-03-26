// Problem Number: 152
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        int result = nums[0];
        int maxProduct = 1;
        int minProduct = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                maxProduct = 0;
                minProduct = 0;
            }
            if (nums[i] < 0)
            {
                swap(maxProduct, minProduct);
            }
            maxProduct = max(maxProduct * nums[i], nums[i]);
            minProduct = min(minProduct * nums[i], nums[i]);
            result = max(result, maxProduct);
        }
        return result;
    }
};