#include "Header.h"
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

int main()
{
    int size;

    std::cout << "Enter the number of vertices: ";
    std::cin >> size;

    ShortestPath path(size);
    path.initializeGraph();

    std::cout << "\nAdjacency matrix:\n";
    path.printGraph();

    int beginIndex;
    std::cout << "\nEnter the starting vertex: ";
    std::cin >> beginIndex;
    beginIndex--;

    path.dijkstraAlgorithm(beginIndex);
    path.printShortestDistances();

    int endIndex;
    std::cout << "\nEnter the ending vertex for finding the shortest path: ";
    std::cin >> endIndex;
    endIndex--;

    path.findShortestPath(beginIndex, endIndex);

    return 0;
}
