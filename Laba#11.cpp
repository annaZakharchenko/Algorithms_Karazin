#include "Header.h"
#include <iostream>
#include <vector>


int main() 
{
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Graph g(numVertices);

    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Input edges (vertex1 vertex2):\n";
    for (int i = 0; i < numEdges; ++i)
    {
        int v, w;
        cin >> v >> w;

        if (v < 1 || v > numVertices || w < 1 || w > numVertices) 
        {
            cout << "Invalid edge vertices. Please enter valid vertices." << endl;
            return 1;
        }

        g.addEdge(v, w);
    }

    int startVertex, endVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;
    cout << "Enter the ending vertex: ";
    cin >> endVertex;

    g.findAllPaths(startVertex, endVertex);

    return 0;
}
