#include <queue>
#include <unordered_map>
#include <vector>

// Pair to represent points on the graph
using Point = std::pair<int, int>;

// Priority queue where the Point with the highest priority (lowest f score) is always at the front
using PriorityQueue = std::priority_queue<std::pair<int, Point>, std::vector<std::pair<int, Point>>, std::greater<std::pair<int, Point>>>;

// Heuristic function for Greedy Best-First Search (Manhattan distance)
int heuristic(Point a, Point b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// Greedy Best-First Search algorithm
void greedyBestFirstSearch(std::vector<std::vector<int>>& graph, Point start, Point goal) {
    PriorityQueue frontier;
    frontier.push(std::make_pair(0, start));

    std::unordered_map<Point, Point> came_from;
    came_from[start] = start;

    while (!frontier.empty()) {
        Point current = frontier.top().second;
        frontier.pop();

        if (current == goal) {
            break;
        }

        for (Point next : {Point{current.first - 1, current.second}, Point{current.first + 1, current.second}, Point{current.first, current.second - 1}, Point{current.first, current.second + 1}}) {
            if (next.first < 0 || next.first >= graph.size() || next.second < 0 || next.second >= graph[0].size()) {
                continue;
            }

            if (came_from.find(next) == came_from.end()) {
                int priority = heuristic(goal, next);
                frontier.push(std::make_pair(priority, next));
                came_from[next] = current;
            }
        }
    }
}

// 只看启发式函数的值，不考虑路径的成本