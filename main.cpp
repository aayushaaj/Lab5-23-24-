#include <iostream>
#include "graph.h"

int main()
{
    Graph g(5, false);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    std::cout << "Number of vertices: " << g.numVertices() << std::endl;
    std::cout << "Number of edges: " << g.numEdges() << std::endl;
    std::cout << "Is graph directed? " << (g.isDirected() ? "Yes" : "No") << std::endl;

    for (int i = 0; i < g.numVertices(); ++i)
    {
        std::cout << "Degree of vertex " << i << ": " << g.degree(i) << std::endl;
    }

    g.neighbours(1);
    std::cout << "Vertex 1 and 2 are neighbours? " << (g.neighbour(1, 2) ? "Yes" : "No") << std::endl;

    g.addVertex();
    std::cout << "Added vertex. Number of vertices: " << g.numVertices() << std::endl;

    g.removeVertex(1);
    std::cout << "Removed vertex 1. Number of vertices: " << g.numVertices() << std::endl;

    return 0;
}
