// Problem Number: 74
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
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
        {
            return false;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0, right = row * col - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int midElement = matrix[mid / col][mid % col];
            if (midElement == target)
            {
                return true;
            }
            if (midElement < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};