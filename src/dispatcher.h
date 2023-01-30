#ifndef DISPATCHER_H_
#define DISPATCHER_H_

#include "geometric.h"

#include <vector>
#include <string>
#include <iostream>

void output(std::vector<Point> closestPoints);
std::vector<Point> readFile(std::string path, bool* errs);

#endif  // DISPATCHER_H_