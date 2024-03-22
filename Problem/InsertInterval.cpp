// Problem Number: 57
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (newInterval.front() > intervals[i].back())
            {
                merged.push_back(intervals[i]);
                continue;
            }

            if (newInterval.back() >= intervals[i].front())
            {
                newInterval = {min(newInterval.front(), intervals[i].front()),
                               max(newInterval.back(), intervals[i].back())};
                continue;
            }

            merged.push_back(newInterval);

            if (newInterval.back() < intervals[i].front())
            {
                merged.push_back(intervals[i]);
                continue;
            }
        }
        return merged;
    }
};