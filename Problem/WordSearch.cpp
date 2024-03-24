// Problem Number: 79
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool backtrack(vector<vector<char>> &board, string word, int i, int j, int index, vector<vector<bool>> &visited)
    {
        if (index == word.size())
        {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index])
        {
            return false;
        }
        visited[i][j] = true;
        bool down = backtrack(board, word, i + 1, j, index + 1, visited);
        bool up = backtrack(board, word, i - 1, j, index + 1, visited);
        bool right = backtrack(board, word, i, j + 1, index + 1, visited);
        bool left = backtrack(board, word, i, j - 1, index + 1, visited);
        visited[i][j] = false;
        
        return down || up || right || left;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (backtrack(board, word, i, j, 0, visited))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};