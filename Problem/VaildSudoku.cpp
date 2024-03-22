// Problem Number: 36
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<string> seen;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char number = board[i][j];
                if (number != '.')
                {
                    if (!seen.insert(string(1, number) + " in row " + to_string(i)).second ||
                        !seen.insert(string(1, number) + " in column " + to_string(j)).second ||
                        !seen.insert(string(1, number) + " in sub-box " + to_string(i / 3) + "-" + to_string(j / 3)).second)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};