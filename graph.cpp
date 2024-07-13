#include <iostream>
#include "graph.h"

Graph::Graph(int numOfVertices, bool directed) : numOfVertices(numOfVertices), directed(directed) {
    adjMatrix.resize(numOfVertices, std::vector<int>(numOfVertices, 0));
}

int Graph::numEdges() {
    int count = 0;
    for(const auto& row : adjMatrix)
        for(int val : row)
            if(val == 1)
                count++;
    return directed ? count : count / 2;
}

int Graph::indegree(int vertex) {
    int count = 0;
    if(vertex < numOfVertices) {
        for(int i = 0; i < numOfVertices; ++i) {
            if(adjMatrix[i][vertex] == 1)
                count++;
        }
    }
    return count;
}

int Graph::outdegree(int vertex) {
    int count = 0;
    if(vertex < numOfVertices) {
        for(int i = 0; i < numOfVertices; ++i) {
            if(adjMatrix[vertex][i] == 1)
                count++;
        }
    }
    return count;
}

int Graph::degree(int vertex) {
    return directed ? indegree(vertex) + outdegree(vertex) : outdegree(vertex);
}

std::vector<int> Graph::neighbours(int vertex) {
    std::vector<int> neighborsList;
    if(vertex < numOfVertices) {
        for(int i = 0; i < numOfVertices; ++i) {
            if(adjMatrix[vertex][i] == 1) {
                neighborsList.push_back(i);
            }
        }
    }
    return neighborsList;
}

bool Graph::neighbour(int vertex1, int vertex2) {
    if(vertex1 < numOfVertices && vertex2 < numOfVertices) {
        return adjMatrix[vertex1][vertex2] == 1;
    }
    return false;
}
