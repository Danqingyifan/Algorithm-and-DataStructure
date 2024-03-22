// Problem Number: 228
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> result;
        if (nums.size() == 0)
        {
            return result;
        }
        int start = nums[0];
        int end = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == end + 1)
            {
                end = nums[i];
            }
            else
            {
                if (start == end)
                {
                    result.push_back(to_string(start));
                }
                else
                {
                    result.push_back(to_string(start) + "->" + to_string(end));
                }
                start = nums[i];
                end = nums[i];
            }

            //The last check
            if (i == nums.size() - 1)
            {
                if (start == end)
                {
                    result.push_back(to_string(start));
                }
                else
                {
                    result.push_back(to_string(start) + "->" + to_string(end));
                }
            }
        }
        
        return result;
    }
};