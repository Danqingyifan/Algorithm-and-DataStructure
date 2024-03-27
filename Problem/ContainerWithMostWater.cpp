// Problem Number: 11
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        while (left < right)
        {
            maxArea = std::max(maxArea, (right - left) * std::min(height[left], height[right]));
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxArea;
    }
};