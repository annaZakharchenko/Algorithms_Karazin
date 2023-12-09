#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void findAllPaths(int start, int end);

private:
    int vertices;
    vector<vector<int>> adjacencyList;

    void findAllPathsUtil(int start, int end, vector<bool>& visited, vector<int>& path);
};