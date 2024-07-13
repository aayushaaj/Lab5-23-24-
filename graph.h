
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

class Graph
{   
    private:
        int numOfVertices;
        bool directed;
        std::vector<std::vector<int>> adjMatrix;

    public:
        Graph(int numOfVertices, bool directed);

        int numEdges();
        int indegree(int vertex);
        int outdegree(int vertex);
        int degree(int vertex);
        std::vector<int> neighbours(int vertex);
        bool neighbour(int vertex1, int vertex2);
};

#endif
