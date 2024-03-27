// Problem Number: 48
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < row; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};