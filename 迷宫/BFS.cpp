#include <vector>
#include <algorithm>
#include "BFS.h"
#include "Queue.h"
#include "container.h"
std::vector<Point> bfs(const std::vector<std::vector<int>>& maze, Point start, Point end) {
    Queue q;
    initQueue(&q);  // 初始化队列
    std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(maze[0].size(), false));
    std::vector<std::vector<Point>> prev(maze.size(), std::vector<Point>(maze[0].size(), {-1, -1})); // 存储前驱节点
        enqueue(&q, start);
    visited[start.y][start.x] = true;

    while (!isQueueEmpty(&q)) {
        Point current = dequeue(&q);  // 出队

        if (current.x == end.x && current.y == end.y) {
            // 找到出口，回溯路径
            std::vector<Point> path;
            for (Point p = current; p.x != -1 && p.y != -1; p = prev[p.y][p.x]) {
                path.push_back(p);
            }
            std::reverse(path.begin(), path.end()); // 反转路径
            return path; // 返回路径
        }

        for (auto& dir : std::vector<Point>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
            int nx = current.x + dir.x;
            int ny = current.y + dir.y;
            if (nx >= 0 && nx < maze[0].size() && ny >= 0 && ny < maze.size() &&
                maze[ny][nx] == PATH && !visited[ny][nx]) {
                visited[ny][nx] = true;
                prev[ny][nx] = current; // 记录前驱节点
                enqueue(&q, {nx, ny}); // 入队
            }
        }
    }

    return {}; // 未找到路径
}

