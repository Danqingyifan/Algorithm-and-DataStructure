// Problem Number: 35
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[high])
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return nums[low];
    }
};