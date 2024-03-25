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
    int binarySearch(vector<int> &nums, int target, int left, int right)
    {
        if (left > right)
        {
            return left;
        }
        int mid = left + (right - left) / 2;
        if (target == nums[mid])
        {
            return mid;
        }
        if (target > nums[mid])
        {
            return binarySearch(nums, target, mid + 1, right);
        }
        if (target < nums[mid])
        {
            return binarySearch(nums, target, left, mid - 1);
        }
        return left;
    }
    int searchInsert(vector<int> &nums, int target)
    {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};