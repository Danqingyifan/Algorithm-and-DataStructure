#include <queue>
#include <unordered_map>
#include <vector>
#include <limits>
#include <iostream>

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
    int node, cost;

    // 重载<运算符，使得优先队列按照cost从小到大排序
    bool operator<(const QueueNode &other) const
    {
        return cost > other.cost;
    }
};

void dijkstra(const Graph &graph, int start, int goal)
{
    // 优先队列，存储待处理的节点
    priority_queue<QueueNode> frontier;
    frontier.push({start, 0});

    // 两个映射表，存储每个节点的来源和到达每个节点的最小成本
    unordered_map<int, int> came_from, cost_so_far;

    came_from[start] = -1;
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
                int priority = new_cost;
                frontier.push({next, priority});
                came_from[next] = current;
            }
        }
    }

    // 打印路径
    if (came_from.find(goal) != came_from.end())
    {
        for (int current = goal; current != -1; current = came_from[current])
        {
            cout << current << ' ';
        }
        cout << endl;
    }
    else
    {
        cout << "No path found!" << endl;
    }
}

//只看路径成本,不考虑启发式函数的值