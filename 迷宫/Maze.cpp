#include <iostream>
#include <vector>
#include <cstdlib>
#include "Maze.h"
#include "Stack.h"
#include "container.h"


// �Թ����ɺ���
std::vector<std::vector<int>> generateMaze(int width, int height) {
    std::vector<std::vector<int>> maze(height, std::vector<int>(width, WALL));
    Stack s;
    initStack(&s);  // ��ʼ��ջ
    Point start = {1, 1};
    maze[start.y][start.x] = PATH;
    push(&s, start);  // ��ջ

    while (!isEmpty(&s)) {
        Point current = top(&s);
        pop(&s);  // ��ջ

        std::vector<Point> neighbors;
        // ����ĸ�����
        for (auto& dir : std::vector<Point>{{0, 2}, {2, 0}, {0, -2}, {-2, 0}}) {
            int nx = current.x + dir.x;
            int ny = current.y + dir.y;
            if (nx > 0 && nx < width && ny > 0 && ny < height && maze[ny][nx] == WALL) {
                neighbors.push_back({nx, ny});
            }
        }

        if (!neighbors.empty()) {
            push(&s, current); // ����ǰ��Ż�ջ��
            Point next = neighbors[rand() % neighbors.size()]; // ���ѡ��һ���ھ�
                        maze[(current.y + next.y) / 2][(current.x + next.x) / 2] = PATH; // ��ͨǽ��
            maze[next.y][next.x] = PATH; // �����ھ�Ϊ·��
            push(&s, next); // ���ھӼ���ջ��
        }
    }

    return maze;
}

// ��ӡ�Թ�
void printMaze(const std::vector<std::vector<int>>& maze, const Point& start, const Point& end) {
    for (int y = 0; y < maze.size(); ++y) {
        for (int x = 0; x < maze[y].size(); ++x) {
            if (x == start.x && y == start.y) {
                std::cout << "S"; // ���
            } else if (x == end.x && y == end.y) {
                std::cout << "E"; // ����
            } else {
                std::cout << (maze[y][x] == WALL ? "#" : " ");
            }
        }
        std::cout << std::endl;
    }
}
