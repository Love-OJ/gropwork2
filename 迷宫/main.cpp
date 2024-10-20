#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Maze.h"
#include "Point.h"
#include "Queue.h"
#include "Stack.h"
#include "BFS.h"
#include "container.h"
int main() {
    srand(static_cast<unsigned int>(time(0))); // 随机数种子
    int width, height;

    std::cout << "请输入迷宫宽度 (奇数): ";
    std::cin >> width;
    std::cout << "请输入迷宫高度 (奇数): ";
    std::cin >> height;

    // 确保宽度和高度为奇数
    if (width % 2 == 0) width++;
    if (height % 2 == 0) height++;

    std::vector<std::vector<int>> maze = generateMaze(width, height);

    // 打印生成的迷宫
    std::cout << "生成的迷宫如下:" << std::endl;
    printMaze(maze, {0, 0}, {width, height}); // 这里的起点和终点不重要，只是为了打印迷宫

    Point start, end1;

    // 获取用户输入的入口坐标
    std::cout << "请输入入口坐标 (x y): ";
    std::cin >> start.x >> start.y;

    // 获取用户输入的出口坐标
    std::cout << "请输入出口坐标 (x y): ";
    std::cin >> end1.x >> end1.y;

    // 检查输入的坐标是否有效
    if (start.x < 0 || start.x >= width || start.y < 0 || start.y >= height ||
        end1.x < 0 || end1.x >= width || end1.y < 0 || end1.y >= height ||
        maze[start.y][start.x] == WALL || maze[end1.y][end1.x] == WALL) {
        std::cout << "入口或出口位置无效，请确保它们在路径上。" << std::endl;
        return 1;
    }

    // 打印迷宫
    printMaze(maze, start, end1);

    // 使用 BFS 查找路径
    std::vector<Point> path = bfs(maze, start, end1);
    if (!path.empty()) {
        std::cout << "找到从入口到出口的路径! 路径长度为: " << path.size() - 1 << std::endl; // 路径长度为点数减一
        std::cout << "路径为: " << std::endl;
        for (const auto& p : path) {
            std::cout << " (" << p.x << "," << p.y << ") ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "未找到路径." << std::endl;
    }

    return 0;
}
