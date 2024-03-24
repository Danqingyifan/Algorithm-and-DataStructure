// Problem Number: 46
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    void backtrack(vector<vector<int>> &result, vector<int> &current, std::vector<int> &tempVec)
    {
        if (current.size() == 0)
        {
            result.push_back(tempVec);
            return;
        }
        for (int i : current)
        {
            tempVec.push_back(i);
            vector<int> next(current);
            next.erase(std::find(next.begin(), next.end(), i));
            backtrack(result, next, tempVec);
            tempVec.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        std::vector<int> tempStack;
        backtrack(result, nums, tempStack);
        return result;
    }
};