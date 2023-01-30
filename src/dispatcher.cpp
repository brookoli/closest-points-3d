#include "dispatcher.h"

#include <fstream>
#include <sstream>


void output(std::vector<Point> closestPoints) {
    for (auto s : closestPoints) {
        std::cout << "segment " << s.segment << " point " << s.x << " " << s.y << " " << s.z << std::endl;
    }
}

std::vector<Point> readFile(std::string path, bool* errs) {
    std::string line;
    std::ifstream fileNodes(path);
    std::vector<Point> nodes;

    *errs = false;

    if (fileNodes.is_open()) {
        while (getline(fileNodes, line) && !errs) {
            std::stringstream ss(line);
            std::string word;
            double crds[3];
            int counter = 0;
            while (ss >> word && !errs ) {
                try {
                    if (counter < 3)
                        crds[counter] = std::stod(word);
                    counter++;
                }
                catch (...) {
                    std::cout << "Invalid input, try again" << std::endl;
                    *errs = true;
                }
            }
            if (counter == 3) {
                Point p(crds[0], crds[1], crds[2]);
                nodes.push_back(p);
            }
            else {
                if (!errs) {
                    std::cout << "Wrong coordinates" << std::endl;
                    *errs = true;
                }
            }
        }
        fileNodes.close();
    }
    else {
        std::cout << "Failed to read a file" << std::endl;
        *errs = true;
    }
    return nodes;
}