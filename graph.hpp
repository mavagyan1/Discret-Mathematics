#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <string>
#include <queue>

struct Node {
    using adjList = std::vector<int>;
    bool visited{false};
    int distance{0};
    adjList adj;
};

using Nodes = std::vector<Node>;
using Queue = std::queue<Node>;

class Graph {

public:
    Graph(const std::string& filename);
    int  findShortestPath(int source, int destination); 
    std::size_t getSize() const;

private:
    void readGraphFromFile(const std::string& filename);
    void addNode(const std::string& line);
    std::vector<int> stringToVector(const std::string& line);

private:
    Nodes nodes_;
    int   count_;
};  //Graph

#endif  //GRAPH_HPP