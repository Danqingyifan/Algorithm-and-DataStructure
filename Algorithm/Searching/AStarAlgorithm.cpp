#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
// Pair to represent points on the graph
using Point = std::pair<int, int>;

// Priority queue where the Point with the highest priority (lowest f score) is always at the front
using PriorityQueue = std::priority_queue<std::pair<int, Point>, std::vector<std::pair<int, Point>>, std::greater<std::pair<int, Point>>>;
// 对于std::pair，比较操作首先比较第一个元素，如果第一个元素相等，那么比较第二个元素。
// 所以，对于std::priority_queue<std::pair<int, Node>, std::vector<std::pair<int, Node>>, std::greater<std::pair<int, Node>>>
// 队列会首先比较pair中的int，然后（如果需要）比较Node。

// Heuristic function for A* (Manhattan distance)
int heuristic(Point a, Point b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// A* search algorithm
// A* search algorithm
void aStarSearch(std::vector<std::vector<int>> &graph, Point start, Point goal)
{
    PriorityQueue frontier;
    frontier.push(std::make_pair(0, start));

    std::unordered_map<Point, Point> came_from;
    std::unordered_map<Point, int> cost_so_far;

    came_from[start] = start;
    cost_so_far[start] = 0;

    while (!frontier.empty())
    {
        Point current = frontier.top().second;
        frontier.pop();

        if (current == goal)
        {
            break;
        }

        // Include diagonal directions
        // 8个方向
        for (Point next : {Point{current.first - 1, current.second}, Point{current.first + 1, current.second}, Point{current.first, current.second - 1}, Point{current.first, current.second + 1}, Point{current.first - 1, current.second - 1}, Point{current.first + 1, current.second + 1}, Point{current.first - 1, current.second + 1}, Point{current.first + 1, current.second - 1}})
        {
            if (next.first < 0 || next.first >= graph.size() || next.second < 0 || next.second >= graph[0].size())
            {
                continue;
            }

            // 对角线移动的判断是通过检查当前节点和下一个节点在x轴和y轴上的差值是否都为1;
            // If the movement is diagonal, the cost is sqrt(2), otherwise it's 1
            int new_cost = cost_so_far[current] + graph[next.first][next.second] * (abs(next.first - current.first) == 1 && abs(next.second - current.second) == 1 ? 1.41421356 : 1);
            if (cost_so_far.find(next) == cost_so_far.end() || new_cost < cost_so_far[next])
            {
                cost_so_far[next] = new_cost;
                int priority = new_cost + heuristic(goal, next);
                frontier.push(std::make_pair(priority, next));
                came_from[next] = current;
            }
        }
    }
}

// 路径成本与启发式函数的值都被考虑,启发式函数起到了一个指导作用，帮助算法更快地找到目标。

// references:
// https://theory.stanford.edu/~amitp/GameProgramming/AStarComparison.html
// https://www.redblobgames.com/pathfinding/a-star/introduction.html
// https://developer.aliyun.com/article/685477
// https://www.redblobgames.com/pathfinding/a-star/implementation.html#algorithm
