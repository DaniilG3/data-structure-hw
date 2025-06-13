#include "Graph.h"
#include <stack>

Graph::Graph() : numVertices(0) {
    for (int i = 0; i < maxsize; ++i) {
        adjLists[i] = nullptr;
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i) {
        nodePT temp = adjLists[i];
        while (temp) {
            nodePT toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
}

nodePT Graph::createNode(int vertex) {
    nodePT newNode = new node;
    newNode->vertex = vertex;
    newNode->next = nullptr;
    return newNode;
}

void Graph::addVertex(int vertexId) {
    if (numVertices < maxsize) {
        adjLists[numVertices] = createNode(vertexId);
        ++numVertices;
    }
}

void Graph::removeVertex(int vertexId) {
    int index = -1;
    for (int i = 0; i < numVertices; ++i) {
        if (adjLists[i] && adjLists[i]->vertex == vertexId) {
            index = i;
            break;
        }
    }
    if (index == -1) return;

    delete adjLists[index];
    adjLists[index] = adjLists[numVertices - 1];
    adjLists[numVertices - 1] = nullptr;
    --numVertices;
}

void Graph::addEdge(int outVertex, int inVertex) {
    for (int i = 0; i < numVertices; ++i) {
        if (adjLists[i]->vertex == outVertex) {
            nodePT temp = adjLists[i];
            while (temp->next) temp = temp->next;
            temp->next = createNode(inVertex);
            return;
        }
    }
}

void Graph::removeEdge(int outVertex, int inVertex) {
    for (int i = 0; i < numVertices; ++i) {
        if (adjLists[i]->vertex == outVertex) {
            nodePT temp = adjLists[i];
            nodePT prev = nullptr;
            while (temp && temp->vertex != inVertex) {
                prev = temp;
                temp = temp->next;
            }
            if (temp) {
                if (prev) prev->next = temp->next;
                else adjLists[i] = temp->next;
                delete temp;
            }
            return;
        }
    }
}

bool Graph::hasEdge(int outVertex, int inVertex) {
    for (int i = 0; i < numVertices; ++i) {
        if (adjLists[i]->vertex == outVertex) {
            nodePT temp = adjLists[i];
            while (temp) {
                if (temp->vertex == inVertex) return true;
                temp = temp->next;
            }
        }
    }
    return false;
}

std::vector<int> Graph::outEdges(int outVertex) {
    std::vector<int> edges;
    for (int i = 0; i < numVertices; ++i) {
        if (adjLists[i]->vertex == outVertex) {
            nodePT temp = adjLists[i]->next;
            while (temp) {
                edges.push_back(temp->vertex);
                temp = temp->next;
            }
        }
    }
    return edges;
}

std::vector<int> Graph::inEdges(int inVertex) {
    std::vector<int> edges;
    for (int i = 0; i < numVertices; ++i) {
        nodePT temp = adjLists[i]->next;
        while (temp) {
            if (temp->vertex == inVertex) edges.push_back(adjLists[i]->vertex);
            temp = temp->next;
        }
    }
    return edges;
}

std::vector<int> Graph::dfs(int startVertex) {
    std::vector<int> visited;
    std::stack<int> vertexStack;
    bool visitedFlags[maxsize] = {false};

    vertexStack.push(startVertex);
    while (!vertexStack.empty()) {
        int current = vertexStack.top();
        vertexStack.pop();

        if (!visitedFlags[current]) {
            visited.push_back(current);
            visitedFlags[current] = true;

            for (int i = 0; i < numVertices; ++i) {
                if (adjLists[i]->vertex == current) {
                    nodePT temp = adjLists[i]->next;
                    while (temp) {
                        vertexStack.push(temp->vertex);
                        temp = temp->next;
                    }
                }
            }
        }
    }
    return visited;
}

void Graph::Show() {
    std::cout << "Adjacency List:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        nodePT nodePtr = adjLists[i];
        while (nodePtr != nullptr) {
            std::cout << nodePtr->vertex << " ";
            nodePtr = nodePtr->next;
        }
        std::cout << '\n';
    }
}
