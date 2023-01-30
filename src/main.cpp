#include <iostream>
#include <string>
#include <vector>

#include <algorithm>

#include "geometric.h"
#include "dispatcher.h"


int main(int argc, char** argv) {
    if (argc == 5) {
        bool errorFlag = false;
        std::vector<Point> nodes, closest;
        Point coolest(std::stod(argv[2]), std::stod(argv[3]), std::stod(argv[4]));
        
        //read file &
        //parse command (wrong input, too many args, too little args, wrong path, blank file, ...)
        nodes = readFile(argv[1], &errorFlag);

        if (!errorFlag) {
            for (int i = 0; i < nodes.size() - 1; i++) {
                //get projection of a point on the line (plane)
                Point neww = orthogonalProjection(nodes[i], nodes[i + 1], coolest);
                neww.segment = i + 1;
                //find the smallest magnitude
                if (!closest.empty() && neww.squaredMagnitude < closest[0].squaredMagnitude) {
                    closest.clear();
                    closest.push_back(neww);        
                }
                else if (closest.empty() || neww.squaredMagnitude == closest[0].squaredMagnitude) {
                    closest.push_back(neww);
                }
            }
        output(closest);
        }
        
    }
    else
        std::cout << "Wrong input. Try ./test-huawei [PATH TO YOUR COORDINATES FILE] [X COORD] [Y COORD] [Z COORD]" << std::endl;
    
    return 0;
}