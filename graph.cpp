#include <iostream>
#include <stdexcept>
#include "graph.h"

Graph::Graph(int numOfVertices, bool directed) : numOfVertices(numOfVertices), directed(directed)
{
    adjMatrix.resize(numOfVertices, std::vector<int>(numOfVertices, 0));
}

bool Graph::isEmpty()
{
    for (const auto &row : adjMatrix)
    {
        for (int val : row)
        {
            if (val != 0)
                return false
        }
    }
    return true;
}

bool Graph::isDirected()
{
    return directed;
}

void Graph::addEdge(int vertex1, int vertex2)
{
    adjMatrix[vertex1][vertex2] = 1;
    if (!directed)
        adjMatrix[vertex2][vertex1] = 1;
}

void Graph::addVertex()
{
    numOfVertices++;
    for (auto &row : adjMatrix)
    {
        row.push_back(0);
    }
    adjMatrix.push_back(std::vector<int>(numOfVertices, 0));
}

void Graph::removeVertex(int vertex)
{
    if (vertex >= numOfVertices || vertex < 0)
        throw std::out_of_range("Vertex index out of range");

    adjMatrix.erase(adjMatrix.begin() + vertex);
    for (auto &row : adjMatrix)
    {
        row.erase(row.begin() + vertex);
    }
    numOfVertices--;
}

void Graph::removeEdge(int vertex1, int vertex2)
{
    adjMatrix[vertex1][vertex2] = 0;
    if (!directed)
        adjMatrix[vertex2][vertex1] = 0;
}

int Graph::numVertices()
{
    return numOfVertices;
}

int Graph::numEdges()
{
    int count = 0;
    for (const auto &row : adjMatrix)
    {
        for (int val : row)
        {
            if (val != 0)
                count++;
        }
    }
    return directed ? count : count / 2;
}

int Graph::indegree(int vertex)
{
    int count = 0;
    for (int i = 0; i < numOfVertices; ++i)
    {
        if (adjMatrix[i][vertex] != 0)
            count++;
    }
    return count;
}

int Graph::outdegree(int vertex)
{
    int count = 0;
    for (int i = 0; i < numOfVertices; ++i)
    {
        if (adjMatrix[vertex][i] != 0)
            count++;
    }
    return count;
}

int Graph::degree(int vertex)
{
    if (directed)
        return indegree(vertex) + outdegree(vertex);
    else
        return outdegree(vertex); // For undirected graphs, indegree == outdegree
}

void Graph::neighbours(int vertex)
{
    if (vertex >= numOfVertices || vertex < 0)
        throw std::out_of_range("Vertex index out of range");

    std::cout << "Neighbours of vertex " << vertex << ": ";
    for (int i = 0; i < numOfVertices; ++i)
    {
        if (adjMatrix[vertex][i] != 0)
            std::cout << i << " ";
    }
    std::cout << std::endl;
}

bool Graph::neighbour(int vertex1, int vertex2)
{
    return adjMatrix[vertex1][vertex2] != 0;
}
