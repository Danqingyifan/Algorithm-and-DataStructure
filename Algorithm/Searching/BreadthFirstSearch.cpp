#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

// 图的节点结构
struct Node
{
    int value;
    vector<Node *> neighbors;
};

// 图的BFS算法
void bfs(Node* start, Node* target)
{
    // 创建一个队列储存最边缘的节点(与未访问的节点相接)
    queue<Node *> frontier;

    // 创建一个集合用于记录已访问的节点
    vector<Node *> visited;

    // 创建一个映射表用于记录每个节点的来源
    unordered_map<Node *, Node *> came_from;

    // 将起始节点加入队列和已访问集合
    frontier.push(start);
    visited.push_back(start);

    // 起始节点的来源设为自己
    came_from[start] = nullptr;

    // 开始BFS
    while (!frontier.empty())
    {
        // 取出队列中的节点
        Node *current = frontier.front();
        frontier.pop();

        // 处理当前节点
        cout << "Visiting node: " << current->value << endl;

        // 如果当前节点是目标节点，结束搜索
        if (current == target)
        {
            cout << "Found the target node!" << endl;
            break;
        }

        // 遍历当前节点的邻居节点
        for (Node *neighbor : current->neighbors)
        {
            // 如果邻居节点未被访问过，则加入队列和已访问集合
            if (find(visited.begin(), visited.end(), neighbor) == visited.end())
            {
                frontier.push(neighbor);
                visited.push_back(neighbor);
                // 记录邻居节点的来源
                came_from[neighbor] = current;
            }
        }
    }

    // 打印每个节点的来源
    for (auto &pair : came_from)
    {
        if (pair.second == nullptr)
            cout << "Node " << pair.first->value << " came from start" << endl;
        else
            cout << "Node " << pair.first->value << " came from Node " << pair.second->value << endl;
    }
}