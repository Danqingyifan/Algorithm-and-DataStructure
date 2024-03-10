#include <queue>
#include <unordered_map>
#include <limits>
#include <iostream>
#include <vector>

using namespace std;

// 定义图的数据结构
struct Graph
{
    struct Edge
    {
        int to, cost;
    };

    vector<vector<Edge>> adj;

    const vector<Edge> &neighbors(int v) const
    {
        return adj[v];
    }
};

// 定义优先队列中的元素
struct QueueNode
{
    int cost, node;

    bool operator<(const QueueNode &other) const
    {
        return cost > other.cost;
    }
};

void uniformCostSearch(const Graph &graph, int start, int goal)
{
    // 优先队列，存储待处理的节点
    priority_queue<QueueNode> frontier;
    frontier.push({0, start});

    // 一个映射表，存储到达每个节点的最小成本
    unordered_map<int, int> cost_so_far;

    cost_so_far[start] = 0;

    while (!frontier.empty())
    {
        int current = frontier.top().node;
        frontier.pop();

        if (current == goal)
        {
            break;
        }

        for (const auto &edge : graph.neighbors(current))
        {
            int next = edge.to;
            int new_cost = cost_so_far[current] + edge.cost;

            if (cost_so_far.find(next) == cost_so_far.end() || new_cost < cost_so_far[next])
            {
                cost_so_far[next] = new_cost;
                frontier.push({new_cost, next});
            }
        }
    }

    // 打印到达目标节点的最小成本
    if (cost_so_far.find(goal) != cost_so_far.end())
    {
        cout << "Minimum cost to reach goal: " << cost_so_far[goal] << endl;
    }
    else
    {
        cout << "No path found!" << endl;
    }
}