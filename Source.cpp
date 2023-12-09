#include "Header.h"
#include <iostream>
#include <vector>

Graph::Graph(int vertices) : vertices(vertices + 1), adjacencyList(vertices + 1) {}

void Graph::addEdge(int v, int w)
{
    adjacencyList[v].push_back(w);
    adjacencyList[w].push_back(v);
}

void Graph::findAllPathsUtil(int start, int end, vector<bool>& visited, vector<int>& path)
{
    visited[start] = true;
    path.push_back(start);

    if (start == end)
    {
        cout << "Path: ";
        for (int vertex : path)
        {
            cout << vertex << " ";
        }
        cout << endl;
    }
    else
    {
        for (int neighbor : adjacencyList[start])
        {
            if (!visited[neighbor])
            {
                findAllPathsUtil(neighbor, end, visited, path);
            }
        }
    }

    visited[start] = false;
    path.pop_back();
}

void Graph::findAllPaths(int start, int end)
{
    if (start < 1 || start >= vertices || end < 1 || end >= vertices)
    {
        cout << "Invalid start or end vertex." << endl;
        return;
    }

    vector<bool> visited(vertices, false);
    vector<int> path;

    cout << "All paths between " << start << " and " << end << ":\n";
    findAllPathsUtil(start, end, visited, path);
}
