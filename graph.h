#include<iostream>
class Graph
{   
    private:
        int numOfVertices;
        bool directed;
    public:
        Graph(int numOfVertices, bool directed);
        bool isEmpty();
        bool isDirected();
        void addVertex(int newVertex);
        void addEdge(int vertex1,int vertex2);
        void removeVertex(int vertexToRemove);
        void removeEdge(int vertex1,int vertex2);
        int numVertices();
        
        int numEdges();
        int indegree(int vertex);
        int outdegree(int vertex);
        int degree(int vertex);
        int neighbours(int vertex);
        bool neighbour(int vertex1,int vertex2);

};