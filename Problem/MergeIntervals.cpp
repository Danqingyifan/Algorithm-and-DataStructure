// Problem Number: 56
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end());
        std::vector<vector<int>> result;
        int index = 0;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (result[index][1] < intervals[i][0])
            {
                result.push_back(intervals[i]);
                index++;
            }
            else
            {
                vector<int> mergedVec{result[index][0], std::max(intervals[i][1], result[index][1])};
                result.pop_back();
                result.push_back(mergedVec);
            }
        }
        return result;
    }
};