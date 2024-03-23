// Problem Number: 39
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    void backtrack(vector<int> &current, std::stack<int> tempStack)
    {
        if (current.size() == 0)
            return;
        do
        {
            for (int i : current)
            {
                tempStack.push(i);
                vector<int> next(current);
                next.erase(std::remove(next.begin(), next.end(), i), next.end());
                backtrack(next, tempStack);
                tempStack.pop();
            }
        } while (!tempStack.empty());
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        std::stack<int> tempStack;
        backtrack(nums, tempStack);
        return result;
    }
};