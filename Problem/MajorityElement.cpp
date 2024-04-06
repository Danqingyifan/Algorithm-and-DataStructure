// Problem Number: 169
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 1;
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == res)
            {
                count++;
            }
            else
            {
                if (count == 0)
                {
                    res = nums[i];
                    count = 1;
                }
                else
                {
                    count--;
                }
            }
        }
        return res;
    }
};