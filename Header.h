#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

class ShortestPath
{
public:
    explicit ShortestPath(int size);

    void initializeGraph();
    void printGraph() const;
    void dijkstraAlgorithm(int beginIndex);
    void printShortestDistances() const;
    void findShortestPath(int beginIndex, int endIndex) const;

private:
    int findMinIndex() const;

    const int SIZE;
    std::vector<std::vector<int>> am; // adjacency matrix
    std::vector<int> d;               // minimum distance
    std::vector<int> v;               // visited vertices
};
