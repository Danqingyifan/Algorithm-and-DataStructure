// Problem Number: 34
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
    void findLastOccurance(vector<int> &nums, int target, int left, int right, int &result)
    {
        if (left > right)
        {
            return;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            result = mid;
            findLastOccurance(nums, target, mid + 1, right, result);
        }
        else if (nums[mid] < target)
        {
            findLastOccurance(nums, target, mid + 1, right, result);
        }
        else
        {
            findLastOccurance(nums, target, left, mid - 1, result);
        }
    }
    void findFirstOccurance(vector<int> &nums, int target, int left, int right, int &result)
    {
        if (left > right)
        {
            return;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            result = mid;
            findFirstOccurance(nums, target, left, mid - 1, result);
        }
        else if (nums[mid] < target)
        {
            findFirstOccurance(nums, target, mid + 1, right, result);
        }
        else
        {
            findFirstOccurance(nums, target, left, mid - 1, result);
        }
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int firstOccurance = -1, lastOccurance = -1;
        findFirstOccurance(nums, target, left, right, firstOccurance);
        findLastOccurance(nums, target, left, right, lastOccurance);
        return {firstOccurance, lastOccurance};
    }
};