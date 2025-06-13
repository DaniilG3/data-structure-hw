#include "Graph.h"

int main() {
    Graph newGraph;
    int choice;
    do {
        std::cout << "Choose an action:\n"
            "Press 1 to add a vertex to the graph.\n"
            "Press 2 to remove a vertex from the graph.\n"
            "Press 3 to add an edge to the graph.\n"
            "Press 4 to remove an edge from the graph.\n"
            "Press 5 to find an edge in the graph.\n"
            "Press 6 to find the out edges of a vertex.\n"
            "Press 7 to find the in edges of a vertex.\n"
            "Press 8 to perform a DFS search.\n"
            "Press 0 to exit.\n"
            "Enter your choice: ";
        std::cin >> choice;

        int vertex, outVertex, inVertex, startVertex;

        switch (choice) {
        case 1:
            std::cout << "Enter the vertex you want to add: ";
            std::cin >> vertex;
            newGraph.addVertex(vertex);
            newGraph.Show();
            break;
        case 2:
            std::cout << "Enter the vertex you want to remove: ";
            std::cin >> vertex;
            newGraph.removeVertex(vertex);
            newGraph.Show();
            break;
        case 3:
            std::cout << "Enter the out vertex: ";
            std::cin >> outVertex;
            std::cout << "Enter the in vertex: ";
            std::cin >> inVertex;
            newGraph.addEdge(outVertex, inVertex);
            newGraph.Show();
            break;
        case 4:
            std::cout << "Enter the out vertex: ";
            std::cin >> outVertex;
            std::cout << "Enter the in vertex: ";
            std::cin >> inVertex;
            newGraph.removeEdge(outVertex, inVertex);
            newGraph.Show();
            break;
        case 5:
            std::cout << "Enter the out vertex: ";
            std::cin >> outVertex;
            std::cout << "Enter the in vertex: ";
            std::cin >> inVertex;
            if (newGraph.hasEdge(outVertex, inVertex))
                std::cout << "There is an edge between " << outVertex << " and " << inVertex << ".\n";
            else
                std::cout << "There is no edge between " << outVertex << " and " << inVertex << ".\n";
            break;
        case 6:
            std::cout << "Enter the out vertex: ";
            std::cin >> outVertex;
            {
                std::vector<int> outEdges = newGraph.outEdges(outVertex);
                std::cout << "The out edges of " << outVertex << " are: ";
                for (const int& edge : outEdges)
                    std::cout << edge << " ";
                std::cout << std::endl;
            }
            break;
        case 7:
            std::cout << "Enter the in vertex: ";
            std::cin >> inVertex;
            {
                std::vector<int> inEdges = newGraph.inEdges(inVertex);
                std::cout << "The in edges of " << inVertex << " are: ";
                for (const int& edge : inEdges)
                    std::cout << edge << " ";
                std::cout << std::endl;
            }
            break;
        case 8:
            std::cout << "Enter the start vertex: ";
            std::cin >> startVertex;
            {
                std::vector<int> searchResults = newGraph.dfs(startVertex);
                std::cout << "DFS traversal starting from " << startVertex << " is: ";
                for (const int& vertex : searchResults)
                    std::cout << vertex << " ";
                std::cout << std::endl;
            }
            break;
        case 0:
            std::cout << "Exiting the program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
