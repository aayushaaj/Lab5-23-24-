
#include "graph.h"
#include <iostream>

int main() {
    
    Graph g(5, false);

   
    std::cout << "Number of edges: " << g.numEdges() << std::endl;

    std::cout << "Neighbours of vertex 1: ";
    for(int v : g.neighbours(1)) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    std::cout << "Degree of vertex 1: " << g.degree(1) << std::endl;
    std::cout << "Indegree of vertex 1: " << g.indegree(1) << std::endl;
    std::cout << "Outdegree of vertex 1: " << g.outdegree(1) << std::endl;

    return 0;
}
