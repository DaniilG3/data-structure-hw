#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

// Node structure
struct node {
    int vertex;
    node* next;
};

typedef node* nodePT;

const int maxsize = 100;

class Graph {
private:
    int numVertices;
    nodePT adjLists[maxsize];

    nodePT createNode(int vertex);

public:
    Graph();
    ~Graph();
    void addVertex(int vertexId);
    void removeVertex(int vertexId);
    void addEdge(int outVertex, int inVertex);
    void removeEdge(int outVertex, int inVertex);
    bool hasEdge(int outVertex, int inVertex);
    std::vector<int> outEdges(int outVertex);
    std::vector<int> inEdges(int inVertex);
    std::vector<int> dfs(int startVertex);
    void Show();
};

#endif // GRAPH_H
