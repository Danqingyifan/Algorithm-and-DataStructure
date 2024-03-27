// Problem Number: 207
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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            count++;
            for (auto &neighbour : adj[curr])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }
        return count == numCourses;
    }
};