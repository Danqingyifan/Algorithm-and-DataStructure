// Problem Number: 994
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        if (fresh == 0)
        {
            return 0;
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int time = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto curr = q.front();
                q.pop();
                for (auto &dir : dirs)
                {
                    int x = curr.first + dir.first;
                    int y = curr.second + dir.second;
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        q.push({x, y});
                        fresh--;
                    }
                }
            }
            time++;
        }
        
        return fresh == 0 ? time - 1 : -1;
    }
};