#include <vector>
#include <algorithm>
#include "BFS.h"
#include "Queue.h"
#include "container.h"
std::vector<Point> bfs(const std::vector<std::vector<int>>& maze, Point start, Point end) {
    Queue q;
    initQueue(&q);  // ��ʼ������
    std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(maze[0].size(), false));
    std::vector<std::vector<Point>> prev(maze.size(), std::vector<Point>(maze[0].size(), {-1, -1})); // �洢ǰ���ڵ�
        enqueue(&q, start);
    visited[start.y][start.x] = true;

    while (!isQueueEmpty(&q)) {
        Point current = dequeue(&q);  // ����

        if (current.x == end.x && current.y == end.y) {
            // �ҵ����ڣ�����·��
            std::vector<Point> path;
            for (Point p = current; p.x != -1 && p.y != -1; p = prev[p.y][p.x]) {
                path.push_back(p);
            }
            std::reverse(path.begin(), path.end()); // ��ת·��
            return path; // ����·��
        }

        for (auto& dir : std::vector<Point>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
            int nx = current.x + dir.x;
            int ny = current.y + dir.y;
            if (nx >= 0 && nx < maze[0].size() && ny >= 0 && ny < maze.size() &&
                maze[ny][nx] == PATH && !visited[ny][nx]) {
                visited[ny][nx] = true;
                prev[ny][nx] = current; // ��¼ǰ���ڵ�
                enqueue(&q, {nx, ny}); // ���
            }
        }
    }

    return {}; // δ�ҵ�·��
}

