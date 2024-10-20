#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "Point.h"

std::vector<std::vector<int>> generateMaze(int width, int height);
void printMaze(const std::vector<std::vector<int>>& maze, const Point& start, const Point& end);

#endif // MAZE_H
