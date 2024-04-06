// Problem Number: 128
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        std::unordered_set<int> numsSet;
        for(int num : nums)
        {
            numsSet.insert(num);
        }
        int longestNum = 0;
        for(int num : nums)
        {
            if (numsSet.find(num - 1) == numsSet.end())
            {
                int current = num;
                int lengthOfCurrentSequence = 1;
                while (numsSet.find(current + 1) != numsSet.end())
                {
                    current++;
                    lengthOfCurrentSequence++;
                }
                longestNum = std::max(longestNum,lengthOfCurrentSequence);
            }
        }
        return longestNum;
    }
};