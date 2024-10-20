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
    srand(static_cast<unsigned int>(time(0))); // ���������
    int width, height;

    std::cout << "�������Թ���� (����): ";
    std::cin >> width;
    std::cout << "�������Թ��߶� (����): ";
    std::cin >> height;

    // ȷ����Ⱥ͸߶�Ϊ����
    if (width % 2 == 0) width++;
    if (height % 2 == 0) height++;

    std::vector<std::vector<int>> maze = generateMaze(width, height);

    // ��ӡ���ɵ��Թ�
    std::cout << "���ɵ��Թ�����:" << std::endl;
    printMaze(maze, {0, 0}, {width, height}); // ����������յ㲻��Ҫ��ֻ��Ϊ�˴�ӡ�Թ�

    Point start, end1;

    // ��ȡ�û�������������
    std::cout << "������������� (x y): ";
    std::cin >> start.x >> start.y;

    // ��ȡ�û�����ĳ�������
    std::cout << "������������� (x y): ";
    std::cin >> end1.x >> end1.y;

    // �������������Ƿ���Ч
    if (start.x < 0 || start.x >= width || start.y < 0 || start.y >= height ||
        end1.x < 0 || end1.x >= width || end1.y < 0 || end1.y >= height ||
        maze[start.y][start.x] == WALL || maze[end1.y][end1.x] == WALL) {
        std::cout << "��ڻ����λ����Ч����ȷ��������·���ϡ�" << std::endl;
        return 1;
    }

    // ��ӡ�Թ�
    printMaze(maze, start, end1);

    // ʹ�� BFS ����·��
    std::vector<Point> path = bfs(maze, start, end1);
    if (!path.empty()) {
        std::cout << "�ҵ�����ڵ����ڵ�·��! ·������Ϊ: " << path.size() - 1 << std::endl; // ·������Ϊ������һ
        std::cout << "·��Ϊ: " << std::endl;
        for (const auto& p : path) {
            std::cout << " (" << p.x << "," << p.y << ") ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "δ�ҵ�·��." << std::endl;
    }

    return 0;
}
