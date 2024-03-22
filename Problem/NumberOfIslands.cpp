// Problem Number: 200
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;
class Solution
{
public:
    int count = 0;
    set<std::pair<int, int>> explored;

    void DFS(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1'||explored.find({i, j}) != explored.end())
            return;
        explored.insert({i, j});
        DFS(grid, i + 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i - 1, j);
        DFS(grid, i, j - 1);
    }
    int numIslands(vector<vector<char>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1' && explored.find({i, j}) == explored.end())
                {
                    DFS(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> grid = {{'1','1','0'},{'1','0','1'}};
    solution.numIslands(grid);
}
