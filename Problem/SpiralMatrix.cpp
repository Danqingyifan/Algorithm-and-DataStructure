// Problem Number: 54
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        std::vector<int> result;
        if (matrix.size() == 0)
        {
            return result;
        }

        set<pair<int, int>> visited;
        vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        pair<int, int> current = {0, 0};
        int currentDirIndex = 0;

        while (!visited.count({current.first, current.second}) && visited.size() < matrix.size() * matrix[0].size())
        {
            visited.insert({current.first, current.second});
            result.push_back(matrix[current.first][current.second]);
            bool changeDir = (current.first + dirs[currentDirIndex].first >= matrix.size() ||
                              current.first + dirs[currentDirIndex].first < 0 ||
                              current.second + dirs[currentDirIndex].second >= matrix[0].size() ||
                              current.second + dirs[currentDirIndex].second < 0 ||
                              visited.count({current.first + dirs[currentDirIndex].first, current.second + dirs[currentDirIndex].second}));
            if (changeDir)
            {
                currentDirIndex = (currentDirIndex + 1) % 4;
            }
            current.first += dirs[currentDirIndex].first;
            current.second += dirs[currentDirIndex].second;
        }
        return result;
    }
};