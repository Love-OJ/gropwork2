#include <iostream>
#include <vector>
#include <cstdlib>
#include "Maze.h"
#include "Stack.h"
#include "container.h"


// 迷宫生成函数
std::vector<std::vector<int>> generateMaze(int width, int height) {
    std::vector<std::vector<int>> maze(height, std::vector<int>(width, WALL));
    Stack s;
    initStack(&s);  // 初始化栈
    Point start = {1, 1};
    maze[start.y][start.x] = PATH;
    push(&s, start);  // 入栈

    while (!isEmpty(&s)) {
        Point current = top(&s);
        pop(&s);  // 出栈

        std::vector<Point> neighbors;
        // 检查四个方向
        for (auto& dir : std::vector<Point>{{0, 2}, {2, 0}, {0, -2}, {-2, 0}}) {
            int nx = current.x + dir.x;
            int ny = current.y + dir.y;
            if (nx > 0 && nx < width && ny > 0 && ny < height && maze[ny][nx] == WALL) {
                neighbors.push_back({nx, ny});
            }
        }

        if (!neighbors.empty()) {
            push(&s, current); // 将当前点放回栈中
            Point next = neighbors[rand() % neighbors.size()]; // 随机选择一个邻居
                        maze[(current.y + next.y) / 2][(current.x + next.x) / 2] = PATH; // 打通墙壁
            maze[next.y][next.x] = PATH; // 设置邻居为路径
            push(&s, next); // 将邻居加入栈中
        }
    }

    return maze;
}

// 打印迷宫
void printMaze(const std::vector<std::vector<int>>& maze, const Point& start, const Point& end) {
    for (int y = 0; y < maze.size(); ++y) {
        for (int x = 0; x < maze[y].size(); ++x) {
            if (x == start.x && y == start.y) {
                std::cout << "S"; // 入口
            } else if (x == end.x && y == end.y) {
                std::cout << "E"; // 出口
            } else {
                std::cout << (maze[y][x] == WALL ? "#" : " ");
            }
        }
        std::cout << std::endl;
    }
}
